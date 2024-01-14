#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <vector>
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
							 "make order", "logout", "ban user", "sell item"};
	vector<bool> guestCommands	 { 1, 1, 1, 1, 0, 0, 0, 0, 0 };
	vector<bool> consumerCommands{ 1, 0, 0, 1, 1, 1, 1, 0, 1 };
	vector<bool> adminCommands	 { 1, 0, 0, 1, 0, 0, 1, 1, 0 };
	//vector<bool> vendorCommands	 { 1, 0, 0, 1, 0, 0, 0, 0 };

	vector<bool>* availableCommands = &guestCommands;



public:
	void addProduct(Product* product);
	void displayProducts();
	static int getTotalProducts();

	void startLoop();
	void receiveCommand();

	void registerUser() { cout << "register" << endl; };
	void loginUser() { cout << "login" << endl; };
	

};


#endif STORE_H;










