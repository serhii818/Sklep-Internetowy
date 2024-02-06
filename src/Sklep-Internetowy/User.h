#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
protected:
	static int usersCount;
	string username;
	string password;

public:
	User() = default;
	//virtual void say();
	virtual ~User() = default;
	User(string name, string password);
	string getUserName() const { return this->username; }
	string getUserPassword() const { return password; }
	virtual void displayInfo() = 0;
	static int getTotalUsers();


};
#endif // USER_H