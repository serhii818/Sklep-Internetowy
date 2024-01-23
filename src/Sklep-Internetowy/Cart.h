// Cart.h
#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"
using namespace std;

class Cart {
public:
    void addItem(Product product);
    void displayCart();
    Cart();
    double calculateTotalPrice();

    vector<Product>& getItems();
    
protected:
    vector<Product> items;
    
};

#endif // CART_H

