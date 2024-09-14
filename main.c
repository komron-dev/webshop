#include "webshop_dec.h"
#include <stdlib.h>
#include <stdio.h>
int main() {
    Set store, cart;

    initializeSet(&store);
    initializeSet(&cart);

    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename to load the webshop store from: ");
                char filename[50];
                scanf("%s", filename);
                loadStoreFromFile(&store, filename);
                break;

            case 2:
                printf("Enter the filename to write the content of the store to: ");
                scanf("%s", filename);
                writeStoreToFile(&store, filename);
                break;

            case 3:
                printf("\n");
                int quantity = 0;
                char productName[50];
                
                printf("Enter product name: ");
                scanf("%s", productName);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                insertItemToCart(&store, &cart, productName, quantity);
                break;

            case 4:
                printf("");
                int sum = getPriceOfCart(&cart);
                printf("Price of the cart: %d\n", sum);
                break;

            case 5:
                buyProducts(&store, &cart);
                break;

            case 6:
                printf("Enter product name: ");
                Product product;
                scanf("%s", product.name);
                printf("Enter product price: ");
                scanf("%d", &product.price);
                printf("Enter product quantity: ");
                scanf("%d", &product.quantity);
                insertItemToStore(&store, product);
                break;
            case 7:
                printf("EXITED\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 7);

    free(store.products);
    free(cart.products);
}
