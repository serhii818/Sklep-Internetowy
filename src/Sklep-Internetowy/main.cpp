#include <iostream>
#include "User.h"
using namespace std;

int main() {

	User user("John", "John");
	user.say();
	cout << endl;
	cout << user.getName() << "\n";
	cout << user.getSurname();
	return 0;

}