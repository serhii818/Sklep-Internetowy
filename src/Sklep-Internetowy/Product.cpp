#include "Product.h"


Product::Product(std::string name, double price, double discount)
    : name(name), price(price), discount(discount) {}

Product::Product() : name(""), price(0.0), discount(0.0) {}

double Product::getPrice() {
    return price;
}

double Product::getDiscount() {
    return discount;
}

string Product::getName() {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
    os << product.name << " " << product.price << " " << product.discount;
    return os;
}

std::istream& operator>>(std::istream& is, Product& product)
{
    is >> product.name >> product.price >> product.discount;

    return is;
}



