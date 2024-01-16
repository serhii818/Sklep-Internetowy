#include "Store.h"

string selectWord(int n, string str) {
    size_t end_;
    for (int i = 0; i < n-1; i++) {
        size_t end_ = str.find(" ");
        str = str.substr(end_+1, str.length() + end_);
    }
    end_ = str.find(" ");
    str = str.substr(0, end_);
    return str;
}

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
    cout << "\n----Available Commands----" << endl;
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
            //loginUser(); // do now
            break;
        case 3:
            displayProducts(); // rewrite
            break;
        case 4:
        {
            Consumer* cons_ptr = dynamic_cast<Consumer*>(loggedUser);
            cons_ptr->addProductToCart(); // finish
        }
            break;
        case 5:
            //makeAnOrder();
            break;
        case 6:
            logout();
            break;
        case 7:
            //banUser();
            break;
        case 8:
            //sellProduct();
            break;
        case 9:
            //show cart();
        default:
            cout << "Command unrecognised" << endl;
            break;
        }
    }
    else {
        cout << "selected command is unavailable" << endl;
    }
}

bool Store::registerUser() {
    bool isExists = false;
    ifstream file("Users.txt");
    string line;
    string name;
    string email;
    string password;
    string address;
    int phone;
    int creditCardNumber;
    int creditCardExpDate;
    int creditCardCvv;
    // at beggining isExists variable set to faslse so normaly loop will execute one time
    // but if user enters already existing name or email it will skip curent itteration
    // and start from begging
    do {
        isExists = false;


        cout << "user name: ";
        cin >> name;
        // checking if entered name already exists
        while (getline(file, line)) {
            if (name == selectWord(1, line)) {
                isExists = true;
                cout << "such username already exists, try different name" << endl;
                break;
            }
        }
        
        if (isExists) continue;
        file.clear();
        file.seekg(0, ios::beg);

        cout << "user email: ";
        cin >> email;
        // checking if entered email already exists
        while (getline(file, line)) {
            if (email == selectWord(4, line)) {
                isExists = true;
                cout << "such email already exists, try different name" << endl;
                break;
            }
        }

        if (isExists) continue;

 // double check
        cout << "password: ";
        cin >> password;

        cout << "user address: ";
        cin >> address;

        cout << "user phone number: ";
        cin >> phone;

        cout << "your credit card number: ";
        cin >> creditCardNumber;

        cout << "your credit card expirational date: ";
        cin >> creditCardExpDate;

        cout << "your credit card cvv: ";
        cin >> creditCardCvv;

        Consumer* cons = new Consumer(name, password, address, phone, email);
        cons->setCreditNumber(creditCardNumber);
        cons->setExpirationDate(creditCardExpDate);
        cons->setCvv(creditCardCvv);

        loggedUser = cons;
        availableCommands = &consumerCommands;

        cons->saveToFile("Users.txt");
    } while (isExists);
    file.close();
    return true;
}

bool Store::loginUser() {
    return false;
}

void Store::logout() {
    loggedUser = nullptr;
    availableCommands = &guestCommands;
}