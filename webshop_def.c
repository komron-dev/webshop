#include "webshop_dec.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void initializeSet(Set* set) {
    set->count = 0;
    set->products = NULL;
}

void loadStoreFromFile(Set* store, char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char name[50];
    int price;
    int quantity;
    while (fscanf(file, "%s %d %d", name, &price, &quantity) == 3)
    { 
        store->products = realloc(store->products, (store->count+1) * sizeof(Product));

        strcpy(store->products[store->count].name, name);
        store->products[store->count].price = price;
        store->products[store->count].quantity = quantity;
        
        store->count++;
    }
    printf("Content of the store\n");
    for (int i = 0; i < store->count; i++)
    {
        printf("%s %d %d\n", store->products[i].name, store->products[i].price, store->products[i].quantity);
    }

    fclose(file);
}

void writeStoreToFile(Set* store, char* filename) {
    FILE *file = fopen(filename, "w");
     if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < store->count; i++)
    {
        fprintf(file, "%s %d %d\n", store->products[i].name, store->products[i].price, store->products[i].quantity);
    }
    
    fclose(file);
}
int findProductIndex(Product *arr, int size, char *productName) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(arr[i].name, productName) == 0) {
            return i;
        }
    }
    return -1;
}

void insertItemToStore(Set* store, Product product) {
    int index = findProductIndex(store->products, store->count, product.name);
    if (index == -1)
    {
        store->products = realloc(store->products, (store->count+1) * sizeof(Product));
        store->products[store->count].price = product.price;
        store->products[store->count].quantity = product.quantity;
        strcpy(store->products[store->count].name, product.name);
        store->count++;
    } else
    {
        store->products[index].quantity += product.quantity;
    }
    
    printf("New product added successfully to the store");
}

void insertItemToCart(Set* store, Set* cart, char *productName, int quantity) {
    int storeIndex = findProductIndex(store->products, store->count, productName);
    if (storeIndex == -1) {
        printf("Product not found in store.\n");
        return;
    }
    
    if (cart->count == 0)
    {
        add:
        cart->products = realloc(cart->products, (cart->count+1) * sizeof(Product));
        cart->products[cart->count].price = store->products[storeIndex].price;
        strcpy(cart->products[cart->count].name, store->products[storeIndex].name);
        cart->products[cart->count].quantity = quantity;
        cart->count++;
        goto end;
    }
    int cartIndex = findProductIndex(cart->products, cart->count, productName);
    if (cartIndex == -1) {
        goto add;
    } else {
        cart->products[cartIndex].quantity += quantity;
    }

    end:
    printf("Content of the cart\n");
    for (int i = 0; i < cart->count; i++)
    {
        printf("%s %d %d\n", cart->products[i].name, cart->products[i].price, cart->products[i].quantity);
    }
    
}

int getPriceOfCart(Set* cart) {
    int sum = 0;
    for (int i = 0; i < cart->count; i++){
        sum += cart->products[i].price * cart->products[i].quantity;
    }

    return sum;
}

void buyProducts(Set* store, Set* cart) {
    for (int i = 0; i < cart->count; i++) {
        int storeIndex = findProductIndex(store->products, store->count, cart->products[i].name);
        if (storeIndex == -1) {
            printf("%d %s are missing.\n", cart->products[i].quantity, cart->products[i].name);
        } else {
            int diff = store->products[storeIndex].quantity - cart->products[i].quantity;
            if (diff > 0) {
                store->products[storeIndex].quantity = diff;
            } else {
                for (int j = storeIndex; j < store->count - 1; j++)
                    store->products[j] = store->products[j+1];
                store->count--;
            }
            if (diff < 0)
                printf("%d %s(s) are missing.\n", abs(diff), cart->products[i].name);
            
        }
    }
    printf("Products bought successfully.\n");
    cart->count = 0;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Load webshop store from a file\n");
    printf("2. Write the content of the store to a file\n");
    printf("3. Insert an item to cart\n");
    printf("4. Get the price of cart\n");
    printf("5. Buy the products\n");
    printf("6. Insert an item to store\n");
    printf("7. Exit the program\n");
    printf("Enter your choice: ");
}
