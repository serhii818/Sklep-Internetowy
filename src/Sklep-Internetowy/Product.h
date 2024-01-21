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
	int amount;
	string seller;
public:
	Product(string name, double price, string seller, double discount = 0.0, int amount = 1);
	Product();
	virtual void displayInfo();
	double getPrice(); 
	double getDiscount(); 
	string getName();
	friend std::ostream& operator<<(std::ostream& os, const Product& product);
	friend std::istream& operator>>(std::istream& is, Product& product);

};


#endif PRODUCT_H

