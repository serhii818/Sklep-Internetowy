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
	virtual void say();
	virtual ~User() = default;
	User(string name, string surname);
	virtual string getUserName() { return this->username; }
	virtual void displayInfo();
	static int getTotalUsers();



};
#endif // USER_H