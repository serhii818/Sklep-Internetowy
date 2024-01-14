#include "Consumer.h"
#include<fstream>

Consumer::Consumer(string username, string password, string address, int phone, string email)
    : User(username, password), address(address), phone(phone), email(email) {}

void Consumer::displayInfo() 
{
    User::displayInfo();
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;

}

void Consumer::makePurchase(Cart cart)
{
    double totalAmount = cart.calculateTotalPrice();
    //Admin::orders.push_back(newOrder);
    cout << "\nMade a purchase for a " + (int)totalAmount << endl;;
    Consumer::creditCard.makePayment();
}

void Consumer::saveToFile(string path) {
    try {
        fstream file;
        file.exceptions(ifstream::badbit | ifstream::failbit);

        file.open(path, ios_base::app);

        if (!file.is_open())
        {
            cout << "Error while trying to open " << path << "while reading" << endl;
        }
        else
        {
            file << '\n' << getUserName() << " " << getUserPassword() << " " << address << " "
                << email << " " << phone << " " << creditCard.getCardNumber() << " "
                << creditCard.getExpirationDate() << " " << creditCard.getCvv();
        }
        file.close();
    }
    catch (const ifstream::failure& e)
    {
        cout << "Error!\n" << e.what() << endl;
        cout << e.code();
    }
}










