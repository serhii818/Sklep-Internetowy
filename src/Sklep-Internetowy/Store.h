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

class Store
{
private:
	vector<Product*> products;
	static int productCount;

	User* loggedUser = nullptr;
	bool programRunning;
	const vector<string> allCommands{ "quit", "register", "login", "show products", "add to cart",
							    "make order", "logout", "ban user", "sell item", "show cart",
								"show my acount"};
	vector<bool> guestCommands	 { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
	vector<bool> consumerCommands{ 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1 };
	vector<bool> adminCommands	 { 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 };
	//vector<bool> vendorCommands	 { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 };

	vector<bool>* availableCommands = &guestCommands;



public:
	void addProduct(Product* product);
	void displayProducts();
	void getProductFromFile(const string&, Product&);
	static int getTotalProducts();

	void startLoop();
	void receiveCommand();

	bool registerUser();
	bool loginUser();
	void logout();
	

};


#endif STORE_H;










