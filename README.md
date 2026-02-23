# Customer Loyalty System

A C++ console application for managing customer loyalty programs, including point tracking, gift redemption, and customer records management.

## Features

- **Customer Management**: Add, edit, and manage customer profiles with loyalty points and rank tiers
- **Gift Catalog**: Maintain a catalog of redeemable gifts with point values and pricing
- **Points System**: Track and manage customer loyalty points with add/deduct functionality
- **Transaction History**: Record all customer transactions including:
  - Points additions
  - Gift redemptions
  - Customer modifications
  - Original point snapshots
- **Customer Search & Sorting**: Find customers and sort by ID or other criteria
- **Gift Management**: Manage gift inventory sorted by point requirements

## Project Structure

- **Group Project Final Version.cpp**: Main application file containing all classes and functions

## Classes

- `Customer`: Stores customer ID, rank, and loyalty points
- `Gift`: Manages gift ID, description, price, and point value
- `addTransaction`: Records point addition transactions
- `redeemTransaction`: Records gift redemption transactions
- `modifyTransaction`: Records customer modifications
- `oiriginalPoint`: Tracks original point records

## Main Menu Options

1. Load Starting Data
2. Show Records
3. Edit Customers
4. Enter Customer View
5. Edit Gifts
6. Display Reports
7. Exit

## Requirements

- C++11 or later compiler
- Windows (optimized with MSVC compiler directive)

## Compilation

```bash
g++ "Group Project Final Version.cpp" -o customer_system.exe
```

Or with your preferred C++ compiler.

## Usage

Run the compiled executable and follow the on-screen menu prompts to:
- Load customer and gift data
- Manage customer loyalty accounts
- Process redemptions
- View transaction history
- Generate reports

## Author

Group Project

## Version

Final Version
