#include "Product.h"


Product::Product(std::string name, double price, double discount)
    : name(name), price(price), discount(discount) {}

double Product::getPrice() {
    return price;
}

double Product::getDiscount() {
    return discount;
}

string Product::getName() {
    return name;
}



