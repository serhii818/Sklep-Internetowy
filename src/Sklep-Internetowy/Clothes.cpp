#include "Clothes.h"

Clothes::Clothes(string name, double price, double discount)
    : Product(name, price, discount) 
{
    clothesCount++;
    id = clothesCount;
}
int Clothes::clothesCount = 0;

int Clothes::getId() { return this->id; }

void Clothes::displayInfo(){
    cout << "Clothing: " << getName() << ", Price: "
        << getPrice() << "$, Discount: " << getDiscount() << endl;
}

Clothes::Clothes() : Product() 
{
    clothesCount++;
    id = clothesCount;
}



