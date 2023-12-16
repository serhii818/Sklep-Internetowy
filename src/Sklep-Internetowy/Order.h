#ifndef ORDER_H
#define ORDER_H
#pragma once

#include <vector>
#include "Product.h"
#include "Cart.h"
#include "Consumer.h"

using namespace std;
class Consumer;

class Order {
public:
    Order(Consumer* consumer, Cart cart);

    void displayOrderDetails();

private:
    Consumer* consumer;
    vector<Product> products;
    
};

#endif 