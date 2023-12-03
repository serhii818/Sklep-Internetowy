#include "Cart.h"
#include <iostream>

void Cart::addItem(Product product) {
    items.push_back(product);
}

void Cart::displayCart() {
    cout << "Cart Contents:\n";
    for (Product item : items) {
        item.displayInfo();
    }
}

double Cart::calculateTotalPrice() {
    double totalPrice = 0.0;
    for (Product item : items) {
        totalPrice += item.getPrice() * (1.0 - item.getDiscount()); // Apply discount
    }
    return totalPrice;
    
}

vector<Product> Cart::getItems()
{
    return items;
}
