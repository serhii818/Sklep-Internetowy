#ifndef ORDER_H
#define ORDER_H
#pragma once

#include <vector>
#include "Product.h"
#include "Cart.h"
#include "Consumer.h"
#include "Safe.h"

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

    void displayOrderDetails();
    int getOrderId();
    void addItem(Product product);
    void showAll();
    double calculateTotalPrice();
    void saveToFile();
    Safe<Product> getItems();

    static int orderCount;

protected:
    Consumer* consumer;
    OrderStatus status;
    int orderId;
    Safe<Product> items;
};

#endif 