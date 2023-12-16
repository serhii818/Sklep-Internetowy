#include "Order.h"
#include <iostream>
#include "Consumer.h"


Order::Order(Consumer* consumer, Cart cart)
{
    for (Product item : cart.getItems()) {
        products.push_back(item);
    }
    this->consumer = consumer;
}

void Order::displayOrderDetails() {
    cout << "Order Details:\n";
    std::cout << "Consumer Information:\n";
    consumer->displayInfo();
    cout << "Products:\n";
    for (Product& prod : products) {
        prod.displayInfo();
    }
}
