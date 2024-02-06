#include "Product.h"


Product::Product(std::string name, double price, string seller, double discount, int amount)
    : name(name), price(price), discount(discount), amount(amount), seller(seller) {}

Product::Product() : name("None"), price(0.0), discount(0.0), seller("None"), amount(0) {}

void Product::displayInfo() {
    cout << name << " " << price << "$ " << discount << "%" << endl;
}

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
    os << product.name << " " << product.price << " " << product.seller << " " << product.discount << " " << product.amount;
    return os;
}

std::istream& operator>>(std::istream& is, Product& product)
{
    is >> product.name >> product.price >> product.seller >> product.discount >> product.amount;

    return is;
}



