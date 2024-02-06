#include "Consumer.h"
#include<fstream>

Consumer::Consumer(string username, string password, string address, int phone, string email)
    : User(username, password), address(address), phone(phone), email(email) {}

void Consumer::displayInfo() 
{
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;

}

void Consumer::makePurchase() {
    // delete selected products from product list in file
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



void Consumer::addProductToCart() {
    ifstream file("Products.txt");
    bool exists = false;
    string productName;
    cout << "enter product name: ";
    cin >> productName;
    Product product;
    while (file >> product) {
        cout << product << product.getName() << endl;
        if (product.getName() == productName) {
            exists = true;
            this->cart.addItem(product);
            break;
        }
    }
    if (file.eof() and not exists) {
        cout << productName << " dont exists in our store" << endl;
    }

    cout << productName << endl;
}


void Consumer::showCart()
{

}
void Consumer::displayCart() {
    this->cart.displayCart();
}

std::istream& operator>>(std::istream& is, Consumer& c) {
    is >> c.username >> c.password >> c.address >> c.email >> c.phone >> c.creditCard.cardNumber >>
        c.creditCard.expirationDate >> c.creditCard.cvv;
    return is;
}

