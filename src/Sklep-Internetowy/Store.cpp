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
        default:
            cout << "Command unrecognised" << endl;
            break;
        }
    }
    else {
        cout << "Command unrecognised, try again" << endl;
    }
}

