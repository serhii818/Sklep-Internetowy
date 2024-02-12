#pragma once
#include <fstream>
#include<sstream>
#include "User.h"
#include "Product.h"
#include "Tools.h"


// class representing companies to buy products from

class Vendor : public User
{
public:

	Vendor() = default;
	Vendor(string username, string password, string address, int phone, string email);
	Vendor(string data);
	void displayInfo() override;

	friend std::istream& operator>>(std::istream& is, Vendor& c);
	friend std::ostream& operator<<(std::ostream& os, const Vendor& c);

private:
	string address;
	int phone;
	string email;
};




