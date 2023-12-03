#include "Consumer.h"
#include "Order.h"


Consumer::Consumer(string username, string password, string address, int phone, string email, Payment::CreditCard payment) : User(username, password), address(address),
    phone(phone), email(email), payment(payment) {}

void Consumer::displayInfo() 
{
    User::displayInfo();
    cout << "Username: " << address << endl;
    cout << "Password: " << password << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;

}

void Consumer::makePurchase(Cart cart)
{
    double totalAmount = cart.calculateTotalPrice();
    Order newOrder(this, cart, payment);
    orders.push_back(newOrder);
    cout << "\nMade a purchase\n";
   
}











