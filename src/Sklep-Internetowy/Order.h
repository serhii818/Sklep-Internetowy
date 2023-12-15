#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Product.h"
#include "Payment.h"
#include "Cart.h"

using namespace std;

class Order {
public:
    Order(/*Consumer* consumer, */Cart cart, Payment::CreditCard payment);

    void displayOrderDetails();

private:
    //Consumer consumer;
    vector<Product> products;
    Payment::CreditCard payment;
};

#endif 