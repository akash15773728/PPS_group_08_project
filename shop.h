#ifndef SHOP_H
#define SHOP_H

#include <stdio.h>
#define MAX_PRODUCTS 10
#define MAX_CART_ITEMS 50

// Structure for a product in the store
typedef struct {
    int id;
    char name[50];
    float price;
} Product;

// Structure for an item inside the user's cart
typedef struct {
    Product *product;   // pointer to product
    int quantity;
} CartItem;

void loadProducts();
void displayProducts();
void addToCart();
void viewCart();
void checkout();
void startShopping();

#endif