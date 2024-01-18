#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product
{
private:
	string name;
	double price;
	double discount;
public:
	Product(string name, double price, double discount = 0.0);
	Product();
	virtual void displayInfo();
	double getPrice(); 
	double getDiscount(); 
	string getName();
	friend std::ostream& operator<<(std::ostream& os, const Product& product);
	friend std::istream& operator>>(std::istream& is, Product& product);
};


#endif PRODUCT_H

