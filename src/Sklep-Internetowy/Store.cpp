#include "Store.h"

int Store::productCount = 0;

void Store::addProduct(Product* product) {
    products.push_back(product);
    productCount++;
}

void Store::displayProducts() {
    std::cout << "Products in the store:\n";
    for (Product* product : products) {
        product->displayInfo();
    }
}

int Store::getTotalProducts() {
    return productCount;
}

/*
Starts main loop of the program where commands can be entered by users
*/
void Store::startLoop() {
    programRunning = true;

    while (programRunning) {
        receiveCommand();
    }

}

/*
shows available commands for current user, receives it and exequtes it.
*/
void Store::receiveCommand() {
    // show avaliabe commands accoresponding to logged user
    cout << "----Available Commands----" << endl;
    for (int i = 0; i < availableCommands->size(); i++) {
        if (availableCommands->at(i)) {
            cout << i << " : " << allCommands[i] << endl;
        }
    }
    cout << "--------------------------\n" << endl;

    // get user input and restrict it according to logged user type
    int command = -1;
    cin >> command;

    if (availableCommands->at(command)) {
        // execute received command
        switch (command)
        {
        case 0:
            programRunning = false;
            break;
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            displayProducts(); //? load from file to vector or read from file directly
            break;
        case 4:
            //add to cart
            break;
        case 5:
            //make order
            break;
        case 6:
            //log out
            break;
        case 7:
            //ban
            break;
        case 8:
            //sell
            break;
        default:
            cout << "Command unrecognised" << endl;
            break;
        }
    }
    else {
        cout << "Command unrecognised, try again" << endl;
    }
}

bool Store::registerUser() {
    string name; // check if exists
    cout << "user name: ";
    cin >> name;
    string password; // double check
    cout << "password: ";
    cin >> password;
    string address;
    cout << "user address: ";
    cin >> address;
    string email;
    cout << "user email: ";
    cin >> email;
    int phone;
    cout << "user phone number: ";
    cin >> phone;
    int creditCardNumber;
    cout << "your credit card number: ";
    cin >> creditCardNumber;
    int creditCardExpDate;
    cout << "your credit card expirational date: ";
    cin >> creditCardExpDate;
    int creditCardCvv;
    cout << "your credit card cvv: ";
    cin >> creditCardCvv;
    
    Consumer* cons = new Consumer(name, password, address, phone, email);
    cons->setCreditNumber(creditCardNumber);
    cons->setExpirationDate(creditCardExpDate);
    cons->setCvv(creditCardCvv);

    loggedUser = cons;
    availableCommands = &consumerCommands;

    cons->saveToFile("Users.txt");
    return true;
}