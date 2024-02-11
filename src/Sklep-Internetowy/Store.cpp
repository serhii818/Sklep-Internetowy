#include "Store.h"


int Store::productCount = 0;

Store::Store() {
    ifstream file("StoreData.txt");
    string line;

    getline(file, line);
    Order::orderCount = stoi(line);

    getline(file, line);
    if (line != "0") {
        Consumer* new_cons = new Consumer{ line };
        loggedUser = new_cons;
        availableCommands = &consumerCommands;
    }
    file.close();
}

Store::~Store() {
    ofstream file("StoreData.txt", ios::trunc);
    file << Order::orderCount << '\n';

    if (loggedUser != nullptr) {
        Consumer* cons = dynamic_cast<Consumer*>(loggedUser);
        file << *cons;
    }
    else {
        file << "0" << '\n';
    }
}

void Store::addProduct(Product product) {
    ofstream file("Products.txt", ios_base::app);
    file << "\n";
    file << product;
    file.close();
}

int Store::getTotalProducts() {
    return productCount;
}
//-----------------------------------------------------------------//
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
            if (loggedUser == nullptr) loginUser();
            break;
        case 3:
            displayProducts();
            break;
        case 4:
        {
            Consumer* cons_ptr = dynamic_cast<Consumer*>(loggedUser);
            cons_ptr->addProductToCart();
        }
            break;
        case 5:
        {
            Consumer* cons_ptr = dynamic_cast<Consumer*>(loggedUser);
            cons_ptr->makePurchase();
        }
            break;
        case 6:
            logout();
            break;
        case 7:
            // CASE 7 PROBLEM WITH CIN
            //     cin.ignore(numeric_limits<streamsize>::max(), '\n');       
            //std::string username;
            //cin >> username;

            //Admin::banUser(username);
            break;
        case 8:
            sellProduct();
            break;
        case 9:
            
            {
                Consumer* cons_ptr = dynamic_cast<Consumer*>(loggedUser);
                cons_ptr->displayCart();
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
//-----------------------------------------------------------------//
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
    // at beggining isExists variable set to false so normaly loop will execute one time
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

        if (isExists) {
            file.clear();
            file.seekg(0, ios::beg);
            continue;
        }

        bool emailExists = false;

        do  {
            cout << "user email: ";
            cin >> email;

            while (getline(file, line)) {
                if (email == selectWord(5, line)) {
                    emailExists = true;
                    cout << "such email already exists, try different email" << endl;
                    break;
                }
            }

            if (emailExists) {
                file.clear();
                file.seekg(0, ios::beg);
                continue;
            }
        

        } while (emailExists);

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

        cons->saveToFile("Users.txt");
    } while (isExists);
    file.close();
    return true;
}

/*
logs in existing user from database
*/
bool Store::loginUser() {
    ifstream file("Users.txt");
    string email;
    string password;
    string data;
  
    while (true) {
        file.clear();
        file.seekg(0, ios::beg);

        cout << "Enter your email: (enter 0 to go back) " << endl;
        cin >> email;
        if (email == "0") { break; }
        data = search(file, 1, email); // returns data with entered email

        cout << "Enter the password: " << endl;
        cin >> password;

        if ((data == "") or (selectWord(2, data) != password)) {
            cout << "email or password are wrong" << endl;
            continue;
        }

        Consumer* new_cons = new Consumer{ data };
        loggedUser = new_cons;
        availableCommands = &consumerCommands;
        cout << "Welcome back " << new_cons->getUserName() << "!" << endl;
        return true;
        break;
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
void Store::displayProducts()
{
    // Try - Catch
    try {
        Product product;
        string filePath = "Products.txt";
        ifstream fileIn;
        //fileIn.exceptions(ifstream::badbit | ifstream::failbit);

        fileIn.open(filePath);

        if (!fileIn.is_open())
        {
            cout << "Error while trying to open " << filePath << "while reading" << endl;
        }
        else
        {
            cout << "File " << filePath << " opened!\nProducts:" << endl;

            while (fileIn >> product) {
                product.displayInfo();
            }
            if (fileIn.eof()) {
                cout << "\nReached the end of the file." << endl;
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

void Store::sellProduct() {
    string name;
    cout << "Enter your product's name: ";
    cin >> name;
    double price;
    cout << "Enter your product's price: ";
    cin >> price;
    double discount;
    cout << "Enter your product's discount: ";
    cin >> discount;
    int amount;
    cout << "Enter quantity of your product: ";
    cin >> amount;
    Product p(name, price, loggedUser->getUserName(), discount, amount);
    addProduct(p);
}

void Store::makeReport(string data)
{
    try {
        string filePath = "report.txt";
        ofstream fileReport("report.txt", ios::app);

        if (!fileReport.is_open())
        {
            cout << "Error while trying to open file." << endl;
        }
        else
        {
            fileReport << data << endl;
        }
        fileReport.close();
    }
    catch (const ifstream::failure& e)
    {
        cout << "Error!\n" << e.what() << endl;
        cout << e.code();
    }
}