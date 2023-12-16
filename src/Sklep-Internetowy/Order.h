#ifndef ORDER_H
#define ORDER_H
#pragma once

#include <vector>
#include "Product.h"
#include "Cart.h"
#include "Consumer.h"

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
    static int orderCount;

private:
    Consumer* consumer;
    vector<Product*> products;
    OrderStatus status;
    int orderId;
};

#endif 