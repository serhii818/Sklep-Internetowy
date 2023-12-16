#pragma once
#include "Product.h"
#include <string>
using namespace std;

class Clothes : public Product
{
public:
    Clothes(string name, double price, double discount = 0.0);
  
    void displayInfo() override;


private:
    string name;
    double price;
    double discount;

};

