#include "User.h"
#include <iostream>

using namespace std;

int User::usersCount = 0;
void User::say() {
	cout << "Hello, " << username;
}

User::User(string username, string password) : username(username), password(password) {
	usersCount++;
}

void User::displayInfo() {
	std::cout << "Username: " << username << std::endl;
}

int User::getTotalUsers() {
	return usersCount;
}




