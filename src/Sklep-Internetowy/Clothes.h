#pragma once
#include "Product.h"
#include <string>
using namespace std;

class Clothes : public Product
{
public:
    Clothes();
    Clothes(string name, double price, double discount = 0.0);
  
    void displayInfo() override;
    static int clothesCount;
    int getId();

private:
    int id;
};

