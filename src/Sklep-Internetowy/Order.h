#ifndef ORDER_H
#define ORDER_H
#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Product.h"
#include "Cart.h"
#include "Consumer.h"
#include "Safe.h"
#include "Consumer.h"
#include "Tools.h"

class Consumer;
class Product;
class Cart;

enum class OrderStatus
{
    Pending,
    Completed,
    Unknown
};

class Order {
public:
    Order(Consumer* consumer, Cart cart);
    Order() = default;
    void displayOrderDetails();
    int getOrderId();
    void addItem(Product product);
    void showAll();
    double calculateTotalPrice();
    void saveToFile(string path);
    Safe<Product> getItems();

    static int orderCount;


protected:
    Consumer* consumer;
    OrderStatus status;
    int orderId;
    Safe<Product> items;
};

#endif 