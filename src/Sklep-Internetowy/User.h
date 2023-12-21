#ifndef USER_H
#define USER_H

#include <iostream>
#include "Clothes.h"
using namespace std;

class User {
protected:
	static int usersCount;
	string username;
	string password;

public:
	User()
	{

	}
	virtual void say();
	virtual ~User() = default;
	User(string name, string surname);
	virtual string getUserName() { return this->username; }
	virtual void displayInfo();
	static int getTotalUsers();
	void getDataFromFile(const string& filePath, Clothes& product);


};
#endif // USER_H