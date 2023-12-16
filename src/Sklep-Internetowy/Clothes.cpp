#include "Clothes.h"

Clothes::Clothes(string name, double price, double discount)
    : Product(name, price, discount) {}

void Clothes::displayInfo(){
    cout << "Clothing: " << getName() << ", Price: "
        << getPrice() << "$, Discount: " << getDiscount() << endl;
}





