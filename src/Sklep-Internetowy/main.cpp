#include <iostream>
#include "User.h"
#include "Cart.h"
#include "Guest.h"
#include "Order.h"
#include "Store.h"
#include "Product.h"
#include "Consumer.h"
#include "Admin.h"
#include <fstream>
#include <chrono>
#include "Vendor.h"
using namespace std;



int main() {

    auto start = std::chrono::high_resolution_clock::now();

    Store store;

    store.startLoop();

    /*
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
    Admin::sortOrders();
    Admin::displayOrders();

    const string path = "C:\\Users\\user\\Desktop\\projectc++\\src\\Sklep-Internetowy\\DataClothing.txt";
    
    Vendor vendor("HasCompany", "rtawyau16", "ul.Wislicka", 789456008, "email.a21@awe");
    vendor.writeProductsToFile(path, laptop);
    cout << "Number of clothes: " << Clothes::clothesCount << endl;
    Clothes newClothe;
    vendor.getDataFromFile(path, newClothe);
    cout << "Id: " << newClothe.getId() <<endl;
    cout << "Number of clothes: " << Clothes::clothesCount << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = (end - start);
    cout << "Duration of the program: " << duration.count() << " seconds" << endl;
    */
   


    return 0;
}






