#pragma once
#include <vector>
#include "Order.h"
#include "User.h"
#include<sstream>

class Order;

class Admin : public User {
private:
    static vector<Order> orders;
    static vector<User> listaUsers;
    string email;

public:
    Admin(string username, string password, string email);
    Admin(string data);
    static void addOrder(Order& order);
    static void banUser(string username);
    static void displayOrders();
    static void sortOrders();
    void displayInfo() override;
};

