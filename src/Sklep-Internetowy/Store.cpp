#include "Store.h"

/*
function for selecting specific word from string
@param n index of word
*/
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
            programRunning = false; // quits main loop
            break;
        case 1:
            registerUser(); // creates new user in file
            break;
        case 2:
            if (loggedUser == nullptr) loginUser(); // loads user data to memory and autorise him
            break;
        case 3:
            displayProducts(); // shows available products for buying
            break;
        case 4:
        {
            Consumer* cons_ptr = dynamic_cast<Consumer*>(loggedUser);
            cons_ptr->addProductToCart(); // finish
        }
            break;
        case 5:
            //makeAnOrder(); // buys products added to cart/
            break;
        case 6:
            logout(); // clears logged user attribute
            break;
        case 7:
            //banUser();
            break;
        case 8:
            //sellProduct(); // adds product to products file
            break;
        case 9:
            {
                Consumer* cons_ptr = dynamic_cast<Consumer*>(loggedUser);
                cons_ptr->displayCart(); // finish
            }
            break;
        case 10:
            loggedUser->displayInfo();
            break;
        default:
            cout << "Command unrecognised" << endl;
            break;
        }
    }
    else {
        cout << "selected command is unavailable" << endl;
    }
}

/*
adds new consumer to database
*/
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
        file.seekg(0, ios::beg); // start reading file from begging

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

        cout << "password: ";
        cin >> password;

        cout << "user address (use underscore instead of spaces): ";
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

/*
logs in existing user from database
*/
bool Store::loginUser() {
    bool wrondData;
    ifstream file("Users.txt");
    string line;
    string email;
    string password;
    int lineNumber = 0; // to track which line contains right data

    do {
        wrondData = true;
        cout << "Enter your email: " << endl;
        cin >> email;
        cout << "Enter the password: " << endl;
        cin >> password;
        // search file for user data
        while (getline(file, line)) {
            lineNumber++;
            if (email == selectWord(4, line) and password == selectWord(2, line)) {
                wrondData = false;
                cout << "Welcome back " << selectWord(1, line) << '!' << endl;
                break;
            }
        }
        if (wrondData) {
            cout << "email or password are wrong" << endl;
        }

    } while (wrondData);

    if (not wrondData) {
        Consumer* new_cons = new Consumer();
        file.clear();
        file.seekg(0, ios::beg); // start reading file from begging

        for (int i = 0; i < lineNumber-1; i++) { // skips line until reaches correct data
            getline(file, line);
        }
        file >> *new_cons;
        
        loggedUser = new_cons;
        availableCommands = &consumerCommands;
        return true;
    }
    
    return false;
}

/*
logs out and deletes previous user object from memory
*/
void Store::logout() {
    delete loggedUser;
    loggedUser = nullptr;
    availableCommands = &guestCommands;
}

/*
loads data to product class object from file
*/
void Store::getProductFromFile(const string& filePath, Product& product)
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