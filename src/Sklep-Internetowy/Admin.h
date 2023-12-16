#pragma once
#include <vector>
#include "Order.h"

class Order;

class Admin {
private:
    static vector<Order> orders;

public:
    static void addOrder(Order& order);
    static void displayOrders();
};

