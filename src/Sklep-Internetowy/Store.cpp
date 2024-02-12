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
            {
            string name;
            cout << "Enter username to ban: ";
            cin >> name;
            Admin* adm = dynamic_cast<Admin*>(loggedUser);
            adm->banUser(name);
            }
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
            cout << "\nCommand unrecognised" << endl;
            break;
        }
    }
    else {
        cout << "\nselected command is unavailable" << endl;
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
                cout << "\nsuch username already exists, try different name" << endl;
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
                    cout << "\nsuch email already exists, try different email" << endl;
                    break;
                }
            }

            if (emailExists) {
                file.clear();
                file.seekg(0, ios::beg);
                continue;
            }
        

        } while (emailExists);

        cout << "\npassword: ";
        cin >> password;

        cout << "\nuser address (use underscore instead of spaces): ";
        cin >> address;

        cout << "\nuser phone number: ";
        cin >> phone;

        cout << "\nyour credit card number: ";
        cin >> creditCardNumber;

        cout << "\nyour credit card expirational date: ";
        cin >> creditCardExpDate;

        cout << "\nyour credit card cvv: ";
        cin >> creditCardCvv;

        Consumer* cons = new Consumer(name, password, address, phone, email);
        cons->setCreditNumber(creditCardNumber);
        cons->setExpirationDate(creditCardExpDate);
        cons->setCvv(creditCardCvv);
        cons->saveToFile("Users.txt");

        stringstream s;
        s << "user " << name << " been created";
        makeReport(s.str());
    } while (isExists);
    file.close();
    return true;
}



/*
logs in existing user from database
*/
bool Store::loginUser() {
    ifstream file("Users.txt");
    ifstream adminFile("Admins.txt");
    ifstream vendorsFile("Vendors.txt");
    ifstream banned("Banned.txt");
    string username;
    string password;
    string data;
    string vendorData;
    string adminData;
    string line_b;

    Admin* new_adm = nullptr;
    Vendor* new_vend = nullptr;
  
    while (true) {
        file.clear();
        file.seekg(0, ios::beg);

        cout << "Enter your username: (enter 0 to go back) " << endl;
        cin >> username;
        if (username == "0") { break; }

        vendorData = search(vendorsFile, 1, username);
        adminData = search(adminFile, 1, username);
        data = search(file, 1, username);

        cout << "Enter the password: " << endl;
        cin >> password;

        while (getline(banned, line_b)) {
            if (line_b == username) {
                cout << "You are banned from using our services" << endl;
                return false;
                break;
            }
        }

        if ((vendorData != "") and (selectWord(2, vendorData) == password)) {
            new_vend = new Vendor{ vendorData };
            loggedUser = new_vend;
            availableCommands = &vendorCommands;
            cout << "Welcome back " << new_vend->getUserName() << "!" << endl;
            stringstream s;
            s << "vendor: " << username << " has logged to store";
            makeReport(s.str());
            return true;
            break;
        }

        if ((adminData != "") and (selectWord(2, adminData) == password) and (new_vend == nullptr)) {
            new_adm = new Admin{ adminData };
            loggedUser = new_adm;
            availableCommands = &adminCommands;
            cout << "Welcome back " << new_adm->getUserName() << "!\nYou are an administrator" << endl;
            stringstream s;
            s << "admin: " << username << " has logged to store";
            makeReport(s.str());
            return true;
            break;
        }

        if ((data != "") and (selectWord(2, data) == password) and (new_adm == nullptr) and (new_vend == nullptr)) {
            Consumer* new_cons = new Consumer{ data };
            loggedUser = new_cons;
            availableCommands = &consumerCommands;
            cout << "Welcome back " << new_cons->getUserName() << "!" << endl;
            stringstream s;
            s << "user: " << username << " has logged to store";
            makeReport(s.str());
            return true;
            break;
        }
        cout << "email or password are wrong" << endl;
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
            cout << "\nProducts:" << endl;

            while (fileIn >> product) {
                product.displayInfo();
            }
            if (fileIn.eof()) {
                cout << "\nThe Store is empty." << endl;
            }
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
    stringstream s;
    s << "product: " << name << " has been added to store";
    makeReport(s.str());
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