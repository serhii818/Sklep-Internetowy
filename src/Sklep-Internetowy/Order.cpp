#include "Order.h"
#include <iostream>
#include <fstream>
#include "Consumer.h"
#include "Tools.h"


Order::Order(Consumer* consumer, Cart cart)
{
    for (Product item : cart.getItems()) {
        items.add(item);
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
    for (Product prod : items.get_vector()) {
        prod.displayInfo();
    }
    this->status = OrderStatus::Completed;
    cout << "Order completed\n";
}

int Order::getOrderId()
{
    return this->orderId;
}

void Order::addItem(Product product) {
    items.add(product);
}

void Order::showAll() {
    cout << "Cart Contents:\n";
    items.showAll();
}

double Order::calculateTotalPrice() {
    double totalPrice = 0.0;
    Safe<Product> temp = items;

    while (!temp.isEmpty()) {
        Product item = temp.show();
        totalPrice += item.getPrice() * (1.0 - item.getDiscount());
        temp.remove();
    }
    return totalPrice;
}

Safe<Product> Order::getItems() {
    return items;
}

void Order::saveToFile() {
    ofstream file("Orders.txt", ios::app);

    file << orderId << " " << (int)status << " " << consumer->getUserName() << " {";
    for (const Product& p : items.get_vector()) {
        file << p << ',';
    }
    file << "}" << endl;

    file.close();
}