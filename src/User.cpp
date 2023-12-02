
#include "User.h"
#include <iostream>

using namespace std;

void User::say() {
	cout << "Hello, " << name << " " << surname;
}

User::User(string imie, string nazwisko) {
	this->name = imie;
	this->surname = nazwisko;
}

string User::getName() { return this->name; }

string User::getSurname() { return this->name; }

