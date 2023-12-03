#ifndef CONSUMER_H
#define CONSUMER_H

#include "User.h"


class Consumer : public User {
public:
    Consumer(string username, string password, string address, int phone, string email, Payment::CreditCard payment);

    void displayInfo() override;
    void makePurchase(Cart cart);

private:
    string address;
    int phone;
    string email;
    Payment::CreditCard payment;
    vector<Order> orders;
};

#endif // CONSUMER_H


