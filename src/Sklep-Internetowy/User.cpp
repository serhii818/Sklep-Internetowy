#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

int User::usersCount = 0;


User::User(string username, string password) : username(username), password(password) {
	usersCount++;
}

void User::displayInfo() {
	std::cout << "Username: " << username << std::endl;
}

int User::getTotalUsers() {
	return usersCount;
}

// (PATH OF THE FILE, PRODUCT OBJECT)
void User::getDataFromFile(const string& filePath, Clothes& product)
{
    // Try - Catch
    try {
        ifstream fileIn;
        fileIn.exceptions(ifstream::badbit | ifstream::failbit);

        fileIn.open(filePath);

        if (!fileIn.is_open())
        {
            cout << "Error while trying to open " << filePath << "while reading" << endl;
        }
        else
        {
            cout << "File " << filePath << " opened!" << endl;

            while (fileIn >> product) {
                cout << product << endl;
            }
            if (fileIn.eof()) {
                cout << "Reached the end of the file." << endl;
            }
            //cart2.addItem(&product);
            //Order newOrder2(&consumer1, cart2);
            //newOrder2.displayOrderDetails();
            //Admin::addOrder(newOrder);
        }
        fileIn.close();
    }
    catch (const ifstream::failure& e)
    {
        cout << "Error!\n" << e.what() << endl;
        cout << e.code();
    }

}



