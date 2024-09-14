#ifndef WEBSHOP_DEC_H
#define WEBSHOP_DEC_H

typedef struct {
    char name[50];
    int price;
    int quantity;
} Product;

typedef struct {
    Product* products;
    int count;
} Set;

void initializeSet(Set* set);
void loadStoreFromFile(Set* store, char* filename);
void writeStoreToFile(Set* store, char* filename);
void insertItemToCart(Set* store, Set* cart, char* productName, int quantity);
void insertItemToStore(Set* store, Product product);
int getPriceOfCart(Set* cart);
void buyProducts(Set* store, Set* cart);
void printMenu();

#endif
