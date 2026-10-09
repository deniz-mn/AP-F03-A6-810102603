"""Run against a freshly started UTaste server: python3 Test/web_smoke.py."""
import http.cookiejar
import urllib.error
import urllib.parse
import urllib.request

base = 'http://localhost:5000'
browser = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(http.cookiejar.CookieJar()))
guest = urllib.request.build_opener()

def request(client, path, data=None):
    payload = None if data is None else urllib.parse.urlencode(data).encode()
    try:
        response = client.open(base + path, payload, timeout=5)
    except urllib.error.HTTPError as error:
        response = error
    with response:
        return response.status, response.read().decode()

assert request(browser, '/')[0] == 200
assert request(browser, '/signup', {'username': 'smoke_user', 'password': 'secret'})[0] == 200
assert request(guest, '/viewReservations')[0] == 403
assert request(guest, '/logout')[0] == 403
assert request(browser, '/viewReservations')[0] == 200
assert request(browser, '/viewRestaurant?name=missing')[0] == 404
assert request(browser, '/viewRestaurant?name=san%20marco')[0] == 200
booking = dict(restaurant_name='lanjin', table_id='1', start_time='10', end_time='11', foods='pizza')
assert request(browser, '/addReservation', dict(booking, table_id='abc'))[0] == 400
assert request(browser, '/addReservation', dict(booking, table_id='1x'))[0] == 400
assert request(browser, '/addReservation', dict(booking, end_time='9'))[0] == 400
status, body = request(browser, '/addReservation', booking)
assert status == 200 and 'lanjin' in body
assert request(browser, '/addReservation', dict(booking, start_time='9', end_time='12'))[0] == 403
assert request(browser, '/viewReservations?restaurant_name=lanjin&reserve_id=abc')[0] == 400
assert request(browser, '/logout')[0] == 200
assert request(browser, '/viewReservations')[0] == 403
assert request(browser, '/login', {'username': 'smoke_user', 'password': 'secret'})[0] == 200
assert 'lanjin' in request(browser, '/viewReservations')[1]
assert request(browser, '/logout')[0] == 200
print('All web smoke checks passed.')
