#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Product.h"
#include "User.h"
#include "Guest.h"
#include "Admin.h"
#include "Vendor.h"
#include "Consumer.h"
#include "Tools.h"

class Store
{
private:
	static int productCount;

	User* loggedUser = nullptr;
	bool programRunning;
	const vector<string> allCommands{ "quit", "register", "login", "show products", "add to cart",
							    "make order", "logout", "ban user", "sell item", "show cart",
								"show my acount"};
	vector<bool> guestCommands	 { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
	vector<bool> consumerCommands{ 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 };
	vector<bool> adminCommands	 { 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 };
	vector<bool> vendorCommands	 { 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 };
	vector<bool>* availableCommands = &guestCommands;

public:
	Store();
	~Store();
	
	void addProduct(Product product);
	void displayProducts();
	static int getTotalProducts();
	void makeReport(std::string data);

	void startLoop();
	void receiveCommand();

	bool registerUser();
	bool loginUser();
	void logout();

	void sellProduct();
	

};


#endif STORE_H;










