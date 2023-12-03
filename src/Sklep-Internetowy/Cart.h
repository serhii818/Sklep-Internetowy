// Cart.h
#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"
class Cart {
public:
    void addItem(Product product);
    void displayCart();
    double calculateTotalPrice();
    vector<Product> getItems();

private:
    std::vector<Product> items;
};

#endif // CART_H

