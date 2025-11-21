#include "shop.h"
#include <string.h>


Product products[MAX_PRODUCTS];
CartItem cart[MAX_CART_ITEMS];
int cartCount = 0;

// Load products into list using array
void loadProducts() {
    products[0] = (Product){1, "Laptop", 55000};
    products[1] = (Product){2, "Mouse", 599};
    products[2] = (Product){3, "Keyboard", 999};
    products[3] = (Product){4, "Headphones", 1499};
    products[4] = (Product){5, "USB Cable", 199};
    products[5] = (Product){6, "Power Bank", 1299};
    products[6] = (Product){7, "Smart Watch", 2499};
    products[7] = (Product){8, "Charger", 799};
    products[8] = (Product){9, "Camera", 35000};
    products[9] = (Product){10, "Monitor", 8500};
}

// Show products
void displayProducts() {
    printf("\n===== PRODUCT LIST =====\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%d. %s  - ₹%.2f\n",
               products[i].id,
               products[i].name,
               products[i].price);
    }
}

// Add item to cart
void addToCart() {
    int id, qty;
    char choice;

    while (1) {
        displayProducts();

        printf("\nEnter Product ID to add: ");
        scanf("%d", &id);

        if (id < 1 || id > MAX_PRODUCTS) {
            printf("Invalid ID!\n");
        } else {
            printf("Enter Quantity: ");
            scanf("%d", &qty);

            if (qty <= 0) {
                printf("Invalid quantity!\n");
            } else {
                cart[cartCount].product = &products[id - 1];
                cart[cartCount].quantity = qty;
                cartCount++;

                printf("Item added successfully!\n");
            }
        }

        // Ask user if they want to add more
        printf("\nDo you want to add more items? (y/n): ");
        scanf(" %c", &choice);   // SPACE before %c to clear buffer

        if (choice == 'n' || choice == 'N') {
            printf("\nReturning to menu...\n");
            break; 
        }
    }
}

// View the cart
void viewCart() {
    if (cartCount == 0) {
        printf("\nCart is empty!\n");
        return;
    }

    printf("\n===== YOUR CART =====\n");
    float total = 0;

    for (int i = 0; i < cartCount; i++) {
        float itemTotal = cart[i].product->price * cart[i].quantity;
        printf("%s x %d = ₹%.2f\n",
               cart[i].product->name,
               cart[i].quantity,
               itemTotal);
        total += itemTotal;
    }

    printf("\nSubtotal: ₹%.2f\n", total);
}

// Checkout with discount
void checkout() {
    if (cartCount == 0) {
        printf("\nCart is empty! Nothing to checkout.\n");
        return;
    }

    float total = 0;

    // Calculate total
    for (int i = 0; i < cartCount; i++) {
        total += cart[i].product->price * cart[i].quantity;
    }

    printf("\n===== CHECKOUT =====\n");
    printf("Subtotal: ₹%.2f\n", total);

    // Discount
    float discount = 0;
    if (total > 5000) {
        discount = total * 0.10;
        printf("Discount (10%%): ₹%.2f\n", discount);
    }

    float finalAmount = total - discount;
    printf("Final Total: ₹%.2f\n", finalAmount);

    // --- Get User Details ---
    char name[50];
    char phone[20];
    char address[100];

  printf("\n===== CUSTOMER DETAILS =====\n");

getchar();

printf("Enter your name: ");
fgets(name, sizeof(name), stdin);

printf("Enter phone number: ");
fgets(phone, sizeof(phone), stdin);

printf("Enter address: ");
fgets(address, sizeof(address), stdin);

name[strcspn(name, "\n")] = 0;
phone[strcspn(phone, "\n")] = 0;
address[strcspn(address, "\n")] = 0;


    // Final confirmation
    printf("\n===== ORDER SUMMARY =====\n");
    printf("Name     : %s\n", name);
    printf("Phone    : %s\n", phone);
    printf("Address  : %s\n", address);
    printf("Amount   : ₹%.2f\n", finalAmount);

    printf("\nOrder Placed Successfully! Thank you for shopping!\n");

    // Clear cart
    cartCount = 0;
}

// Menu
void startShopping() {
    loadProducts();

    int choice;

    while (1) {
        printf("\n===== SHOP MENU =====\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayProducts(); break;
            case 2: addToCart(); break;
            case 3: viewCart(); break;
            case 4: checkout(); break;
            case 5: printf("Thank you for shopping!\n"); return;
            default: printf("Invalid choice!\n");
        }
    }
}
