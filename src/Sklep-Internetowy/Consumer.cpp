#include "Consumer.h"

Consumer::Consumer(string username, string password, string address, int phone, string email)
    : User(username, password), address(address), phone(phone), email(email), banned(false) {
    creditCard = Consumer::CreditCard();
}

Consumer::Consumer(string data) {
    istringstream iss(data);
    iss >> *this;
}

void Consumer::displayInfo() 
{
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;

}

bool Consumer::makePurchase() {
    if ( cart.empty() ) {
        cout << "Your cart is empty" << endl;
        return false;
    }
    Order new_order{this, cart};

    double totalAmount = cart.calculateTotalPrice();
    cout << "Made a purchase for a " << totalAmount << '$' << endl;;
    Consumer::creditCard.makePayment();
    new_order.saveToFile("Orders.txt");


    vector<Product> sold_products = cart.getItems();
    vector<string> products_data = getLines("Products.txt");
    ofstream file("Products.txt", ios::trunc);

    for (string line : products_data) {
        bool sold = false;
        for (Product p : sold_products) {
            if (p.getName() == selectWord(1, line)) {
                sold = true;
            }
        }

        if (not sold) {
            file << line << '\n';
        }
        
    }

    cart.clear();
    return true;
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
        if (product.getName() == productName) {
            exists = true;
            this->cart.addItem(product);
            break;
        }
    }
    if (file.eof() and not exists) {
        cout << productName << " dont exists in our store" << endl;
    }

    file.close();
}

void Consumer::displayCart() {
    this->cart.displayCart();
}

std::ostream& operator<<(std::ostream& os, const Consumer& c) {
    os << c.username << " " << c.password << " " << c.address << " " << c.email << " " << c.phone <<
        " " << c.creditCard.cardNumber << " " <<
        c.creditCard.expirationDate << " " << c.creditCard.cvv << " " << c.banned << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, Consumer& c) {
    is >> c.username >> c.password >> c.address >> c.email >> c.phone >> c.creditCard.cardNumber >>
        c.creditCard.expirationDate >> c.creditCard.cvv >> c.banned;
    return is;
}