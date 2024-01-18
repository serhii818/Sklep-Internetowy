#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

int User::usersCount = 0;
void User::say() {
	cout << "Hello, " << username;
}

User::User(string username, string password) : username(username), password(password) {
	usersCount++;
}

int User::getTotalUsers() {
	return usersCount;
}





