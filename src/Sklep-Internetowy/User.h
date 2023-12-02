#pragma once
#include <iostream>
using namespace std;

class User {
private:
	string name;
	string surname;

public:
	void say();

	User(string name, string surname);

	void setName(string name);
	string getName();
	void setSurname(string name);
	string getSurname();
};
