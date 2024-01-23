#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

int User::usersCount = 0;


User::User(string username, string password) : username(username), password(password) {
	usersCount++;
}

int User::getTotalUsers() {
	return usersCount;
}





