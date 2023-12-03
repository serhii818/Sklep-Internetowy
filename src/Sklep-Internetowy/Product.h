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

	void displayInfo();


	double getPrice() const; 
	double getDiscount() const; 
};


#endif PRODUCT_H
