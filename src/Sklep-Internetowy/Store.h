#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <vector>
#include "Product.h"

class Store
{
private:
	vector<Product*> products;
	static int productCount;

public:
	void addProduct(Product* product);
	void displayProducts();
	static int getTotalProducts();



};


#endif STORE_H;










