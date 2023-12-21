#pragma once
#include <fstream>
#include "User.h"
#include "Clothes.h"

// class representing companies to buy products from

class Vendor : public User
{
public:
	Vendor()
	{

	}
	Vendor(string username, string password, string address, int phone, string email);
	void writeProductsToFile(const string& filePath, Clothes& product);

private:
	string address;
	int phone;
	string email;
};









// USES FUNCTION WRITE_TO_FILE IN MAIN TO WRITE INFORMATION ABOUT PRODUCTS TO THE FILES

