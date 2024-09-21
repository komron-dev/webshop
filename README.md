# Webshop Console Program

This is a console-based webshop management system written in C. It allows users to manage an inventory of products, add items to a cart, calculate total prices, and simulate buying products. The system reads and writes product information from/to a text file and provides basic operations like adding items to the store, adding products to a shopping cart, and completing purchases.

## Features

- **Load Webshop Store:** Load a list of products with prices and quantities from a file.
- **Write Store to File:** Save the current store's products and quantities to a file.
- **Add Item to Cart:** Insert a product into the shopping cart with a specified quantity.
- **Calculate Cart Price:** Calculate the total price of all items in the cart.
- **Purchase Products:** Simulate the purchase by reducing store inventory based on the cart contents.
- **Manage Inventory:** Add new products to the store with their name, price, and quantity.

## File Structure

- **`main.c`:** The main entry point of the application where the menu is displayed and user input is handled.
- **`webshop_def.c`:** Contains the function definitions that implement the business logic of the webshop.
- **`webshop_dec.h`:** Header file that declares the structures and functions used in the program.
- **`store.txt`:** Example text file with product data (product name, price, and quantity) used to initialize the store.

## Usage

### Loading the Store:

- Load the store inventory from a file (e.g., `store.txt`).  
- **File format:** Each line should contain the product name, price, and quantity, separated by spaces.

```
apple 100 9
orange 130 58
raspberry 200 17
```
### Menu Options:

1. Load webshop store from a file.
2. Save the current store to a file.
3. Add a product to the cart.
4. Calculate the total price of the cart.
5. Purchase the products in the cart.
6. Add a new product to the store.
7. Exit the program.

### Compiling and Running:
Used Makefile as a shortcut to run a bit lengthy commands

#### Compile the program:
```
make compile
```
Run the program:
```
make run
```

## Interacting with the Program:
- The program will prompt you for input at various stages, such as entering file names, product names, quantities, and prices.

### Example
```
Menu:
1. Load webshop store from a file
2. Write the content of the store to a file
3. Insert an item to cart
4. Get the price of cart
5. Buy the products
6. Insert an item to store
7. Exit the program
Enter your choice: 1
```

## Dependencies
- Standard C library (<stdio.h>, <stdlib.h>)
