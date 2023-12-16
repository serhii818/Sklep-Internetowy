#include "Order.h"
#include <iostream>
#include "Consumer.h"


Order::Order(Consumer* consumer, Cart cart)
{
    for (Product* item : cart.getItems()) {
        products.push_back(item);
    }
    this->consumer = consumer;
    this->status = OrderStatus::Unknown;
    orderCount++;
    orderId = orderCount;
}
// need to provide more functionality for enum OrderStatus::

int Order::orderCount = 0;

void Order::displayOrderDetails() {
    cout << "Order Details:\n";
    std::cout << "Order ID: " << orderId << "\n";
    std::cout << "Consumer Information:\n";
    consumer->displayInfo();
    cout << "Products:\n";
    for (Product* prod : products) {
        prod->displayInfo();
    }
    this->status = OrderStatus::Completed;
    cout << "Order completed\n";
}

int Order::getOrderId()
{
    return this->orderId;
}


