#include <iostream>
#include "User.h"
#include "Cart.h"
#include "Order.h"
#include "Store.h"
#include "Product.h"
#include "Consumer.h"

using namespace std;

int main() {

	User user("John", "John");
	user.say();
	cout << endl;
    cout << user.getUserName() << "\n";

    Consumer consumer1("user564", "Agr4tr56", "ulica d", 794453343, "reio@gmail");
    consumer1.setCreditNumber(749358402);
    consumer1.setExpirationDate(25.02);
    consumer1.setCvv(908);

    Product laptop("Laptop", 2547);
    Product headphones("Headphones", 55.55, 10);

    Cart cart1;
    cart1.addItem(laptop);
    cart1.addItem(headphones);
    consumer1.makePurchase(cart1);
    Order newOrder(&consumer1, cart1);
    newOrder.displayOrderDetails();
    Admin::addOrder(newOrder);
    Admin::displayOrders();

    return 0;
}





