#include "Cart.h"
#include <iostream>

void Cart::addItem(Product* product) {
    items.add(product);
}

void Cart::displayCart() {
    cout << "Cart Contents:\n";
    items.showAll();
}

double Cart::calculateTotalPrice() {
    double totalPrice = 0.0;
    Fifo<Product*> tempFifo = items;

    while (!tempFifo.isEmpty()) {
        Product* item = tempFifo.front();
        totalPrice += item->getPrice() * (1.0 - item->getDiscount());
        tempFifo.remove();
    }
    return totalPrice;
}

Fifo<Product*> Cart::getItems() {
    return items;
}
