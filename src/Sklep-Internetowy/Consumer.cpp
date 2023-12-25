#include "Consumer.h"

Consumer::Consumer(string username, string password, string address, int phone, string email)
    : User(username, password), address(address), phone(phone), email(email) {}

void Consumer::displayInfo() 
{
    User::displayInfo();
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











