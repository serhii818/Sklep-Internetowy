#include "Product.h"


Product::Product(string name, double price, double discount)
    : name(name), price(price), discount(discount) {}

void Product::displayInfo() {
    cout << "Product: " << name << "\n Price: " << price << "$" << \
        "\n Dicount: " << discount << "$" << endl;
}

double Product::getPrice() const {
    return price;
}

double Product::getDiscount() const {
    return discount;
}



