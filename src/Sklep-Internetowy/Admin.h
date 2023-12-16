#pragma once
#include <vector>
#include "Order.h"
#include "User.h"

class Order;

class Admin : public User {
private:
    static vector<Order> orders;
    string email;

public:
    Admin(string username, string password, string email);
    static void addOrder(Order& order);
    static void displayOrders();
};

