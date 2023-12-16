#include <iostream>
#include "User.h"
#include "Cart.h"
#include "Order.h"
#include "Store.h"
#include "Product.h"
#include "Consumer.h"
#include "Clothes.h"
#include "Admin.h"
#include <fstream>
#include <chrono>

using namespace std;


void getDataFromFile(const string& filePath, Clothes& product)
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

void writePurchasesToFile(const string& filePath, const Clothes& product)
{
    try {
        ofstream fileOut;
        fileOut.open(filePath, ofstream::app);

        if (!fileOut.is_open())
        {
            cout << "Error while trying to open the file " << filePath << "while writing" << endl;
        }
        else
        {
            cout << "File " << filePath << " opened!\n";
            // writing object of the class for example Clothes 
            fileOut << product << "\n";

        }
        fileOut.close();
    }
    catch (const ofstream::failure& e)
    {
        cout << "Error!\n" << e.what() << endl;
        cout << e.code();
    }
}


int main() {

    auto start = std::chrono::high_resolution_clock::now();

	User user("John", "John");
	user.say();
	cout << endl;
    cout << user.getUserName() << "\n";

    Consumer consumer1("user564", "Agr4tr56", "ulica d", 794453343, "reio@gmail");
    consumer1.setCreditNumber(749358402);
    consumer1.setExpirationDate(25.02);
    consumer1.setCvv(908);

    Clothes laptop("Laptop", 2547);
    Clothes headphones("Headphones", 55.55, 10);

    Cart cart1;
    Cart cart2;
    cart1.addItem(&laptop);
    cart1.addItem(&headphones);
    consumer1.makePurchase(cart1);
    Order newOrder(&consumer1, cart1);
    newOrder.displayOrderDetails();
    Admin::addOrder(newOrder);
    Admin::displayOrders();

    string path = "C:\\Users\\user\\Desktop\\projectc++\\src\\Sklep-Internetowy\\DataClothing.txt";
    
    // FIRST FUNCTION
    writePurchasesToFile(path, laptop);


    // SECOND FUNCTION FUNCTION (PATH OF THE FILE, PRODUCT OBJECT)
    cout << "Number of clothes: " << Clothes::clothesCount << endl;
    Clothes newClothe;
    getDataFromFile(path, newClothe);
    cout << "Id: " << newClothe.getId() <<endl;
    cout << "Number of clothes: " << Clothes::clothesCount << endl;

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = (end - start);

    cout << "Duration of the program: " << duration.count() << " seconds" << endl;

    return 0;
}



// template typename T?


