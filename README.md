# UTaste

A local restaurant reservation website built with **C++20**, the bundled **AP HTTP Server**, and HTML/CSS. Users can browse restaurants, view menus and table schedules, and reserve a table with food orders.

## Features

- Sign up, log in, and log out.
- View restaurant locations, opening hours, menus, prices, and discounts.
- Reserve a table using a restaurant name, table ID, start/end hours, and comma-separated food names.
- View reservations, including original and discounted prices.
- Calculate item, first-order, and order-total discounts, with payment from an internal wallet (initial balance: 1,000).
- Reject overlapping bookings for both the table and the user; allow consecutive bookings with matching end/start hours.

## Build and Run

Requires a C++20-capable `g++`, GNU Make, and a POSIX shell (Linux or WSL). From the project directory:

```bash
make -B
./Utaste Test/restaurant.csv Test/neighborhood.csv Test/Discounts.csv
```

`-B` rebuilds the bundled object files from source. Keep the three CSV arguments in this order and run from the project directory so the HTML files can be found.

Open **http://localhost:5000**, sign up, browse restaurants, and select **addReservation**. Example using the included data: restaurant `lanjin`, table `1`, hours `10` to `11`, food `pizza`. Successful bookings redirect to the reservation list.

Use exact restaurant and food names from the menus. Times must be integers with `1 <= start < end <= 24`, within the restaurant's opening hours. Table IDs start at 1. Food names are comma-separated; repeat a name to order multiple portions.

## Project Structure

| Path | Purpose |
| --- | --- |
| `src/` | Domain models, reservation logic, discounts, command parser, and web handlers |
| `server/` | HTTP server and routing |
| `utils/` | Request/response handling, string helpers, and template support |
| `static/` | HTML forms and sample pages |
| `Test/` | Sample CSV data, C++ regression checks, and a Python web smoke test |
| `Makefile` | Build configuration |

## Usage Notes

- Users, wallet balances, and reservations exist only in memory and reset when the server restarts.
- One account can be logged in at a time. Protected actions require that browser's session cookie; log out before switching accounts.
- Reservations are organized by table and hourly time slot.
- The server listens on the local machine only (`127.0.0.1:5000`).
- CSV files have no header row. The supplied files show the expected format; monetary amounts use integer units.

## Checks

Run the domain regression checks from the project directory:

```bash
make test
```

For the browser flow, start a fresh server with the sample CSV files, then run in another terminal (requires Python 3):

```bash
python3 Test/web_smoke.py
```

The checks cover overlapping and adjacent reservations, cancellation IDs, failed orders and first-order discounts, single-item discounts, invalid form input, error pages, and session access. The web test creates a temporary in-memory account named `smoke_user`.
