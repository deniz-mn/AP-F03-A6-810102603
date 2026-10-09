#include "../src/Utaste.hpp"
#include "../utils/request.hpp"
#include <cassert>
#include <functional>

void expect_error(const string& message, const function<void()>& action) {
    bool caught = false;
    try { action(); }
    catch (Exception& error) { caught = error.show_error() == message; }
    assert(caught);
}

int main() {
    auto none = make_shared<Total_discount>(true);
    auto first = make_shared<First_order_discount>(true);
    vector<shared_ptr<Discount>> items;
    auto booking = [&](int id, int start, int end) {
        return make_shared<Reservation>("test", start, end, vector<shared_ptr<Food>>{},
            id, 1, none, first, items, false);
    };

    Person person("user", "password");
    Table table(1);
    auto early = booking(1, 10, 12);
    auto late = booking(2, 16, 18);
    person.save_person_reservation(early);
    person.save_person_reservation(late);
    table.save_table_reservation(early);
    table.save_table_reservation(late);
    assert(person.has_reservation_at(17, 19)); // Must check beyond the first booking.
    assert(person.has_reservation_at(9, 13)); // Full containment is a conflict.
    assert(table.has_reservation_at(9, 13));
    assert(!person.has_reservation_at(12, 16)); // Adjacent bookings are allowed.
    assert(!table.has_reservation_at(12, 16));
    assert(!person.has_reservation_id("test", 99));
    table.delete_reservation_table(2);
    assert(table.get_reservation_by_id(1) == early);
    assert(table.get_reservation_by_id(2) == nullptr);
    assert(early->get_reservation_id() == 1);

    Item_discount capped("amount", 100, "meal");
    assert(capped.apply(50) == 0);
    auto meal = make_shared<Food>("meal", 100);
    auto diner = make_shared<Person>("diner", "password");
    Restaurant restaurant("test", "district", {meal}, 1, 24, 2);
    restaurant.save_discounts({"none"}, {"amount", "10"}, {"amount;meal:20"});
    auto discounted = restaurant.check_reservation_in_restaurant(1, 10, 11, {"meal"}, true, diner);
    assert(discounted->get_final_price() == 70); // One item discount must be loaded.

    Utaste app;
    app.save_restaurant_input("Test/restaurant.csv");
    app.save_neighbors_input("Test/neighborhood.csv");
    app.save_discount_input("Test/Discounts.csv");
    string user = "alice", password = "secret";
    app.signup(user, password);
    expect_error(NOT_FOUND, [&] { app.add_reservation("sib", 1, 10, 11, "missing"); });
    assert(!app.get_login_person()->has_ordered_from("sib"));
    expect_error(BAD_REQUEST, [&] { app.add_reservation("sib", 1, 12, 11, "burger"); });
    expect_error(BAD_REQUEST, [&] { app.add_reservation("sib", 1, 10, 10, "burger"); });
    expect_error(BAD_REQUEST, [&] {
        app.add_reservation("sib", 1, 10, 11, "burger,burger,burger,burger,burger,burger,burger");
    });
    assert(!app.get_login_person()->has_ordered_from("sib"));
    app.add_reservation("sib", 1, 10, 11, " burger ");
    auto saved = app.get_login_person()->find_reservation("sib", 1);
    assert(saved && saved->get_final_price() == 149);
    app.add_reservation("sib", 1, 11, 12, "burger");
    expect_error(PERMISSION_DENIED, [&] { app.add_reservation("sib", 2, 9, 13, "burger"); });
    app.delete_reservation("sib", 2);
    assert(app.get_login_person()->has_reservation_id("sib", 1));
    assert(!app.get_login_person()->has_reservation_id("sib", 2));
    app.add_reservation("sib", 1, 11, 12, "burger");
    assert(app.get_login_person()->has_reservation_id("sib", 3));
    app.logout();
    expect_error(PERMISSION_DENIED, [&] { app.add_reservation("sib", 1, 12, 13, "burger"); });

    Request request("GET");
    request.setHeader("Cookie", "sessionId", false);
    assert(request.getSessionId().empty());
    assert(utils::urlDecode(utils::urlEncode("san marco")) == "san marco");
    cout << "All regression checks passed.\n";
}
