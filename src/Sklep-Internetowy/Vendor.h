#pragma once

#include "User.h"

// class representing companies to buy products from

class Vendor : public User
{
public:
	Vendor() = default;
	Vendor(string username, string password, string address, int phone, string email);


private:
	string address;
	int phone;
	string email;
};



// USES FUNCTION WRITE_TO_FILE IN MAIN TO WRITE INFORMATION ABOUT PRODUCTS TO THE FILES

