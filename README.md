# Movie Ticket Booking System (C++)

A console-based movie ticket booking application written in C++. This project allows users to book seats for a movie show, view seat availability, check ticket prices, and simulate payment, all through a simple terminal interface.

## Features

- **User Authentication:** Login required using credentials from `user.txt` and `password.txt`.
- **Seat Booking:** Select seats from a 10x10 grid, divided into Gold, Platinum, and Silver categories.
- **Seat Availability:** Visual display of available (`#`) and booked (`@`) seats.
- **Price Calculation:** Automatic calculation of total charges based on seat category and quantity.
- **Input Validation:** Checks for valid email and strong password during payment.
- **Simple Payment Page:** Collects user details and simulates payment confirmation.

## Seat Categories & Prices

| Category   | Rows   | Price (per seat) |
|------------|--------|------------------|
| Gold       | 0-4    | ₹250             |
| Platinum   | 5-7    | ₹300             |
| Silver     | 8-9    | ₹200             |

## How to Run

1. **Compile the code:**
   ```sh
   g++ ticket.cpp -o ticket.exe

2. Prepare user and password files:
    user.txt: contains the username (e.g., manish3-4)
    password.txt: contains the password (e.g., 1234)
3. Run the program:
    ```sh
    ticket.exe
    
## Usage
  Login: Enter username and password as prompted.
  Main Menu: Choose to book a show or view prices.
  Booking: Select row and column for seat(s). Book multiple seats if needed.
  Payment: Enter name, email, phone, and set a password. Email and password are validated.
  Confirmation: Enter card details (simulated), and receive booking confirmation.
## File Structure
  ticket.cpp - Main source code
  user.txt - Username for authentication
  password.txt - Password for authentication
## Notes
   The system uses console input/output for interaction.
   Payment is simulated; no actual transaction occurs.
   For demonstration and educational purposes only.
   Works on Windows (use ticket.exe), but can be compiled for other platforms.
