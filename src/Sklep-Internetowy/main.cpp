#include <iostream>
#include "User.h"
#include "Cart.h"
#include "Payment.h"
#include "Order.h"
#include "Store.h"
#include "Product.h"

using namespace std;

int main() {

	User user("John", "John");
	user.say();
	cout << endl;
    cout << user.getUserName() << "\n";
    Payment::CreditCard creditCard(8763804, 522, 055);
    Consumer consumer1("user564", "Agr4tr56", "ulica d", 794453343, "reio@gmail", creditCard);
    Product laptop("Laptop", 2547);
    Product headphones("Headphones", 55.55, 10); 
    Cart cart1;
    cart1.addItem(laptop);
    cart1.addItem(headphones);
    consumer1.makePurchase(cart1);
   
    return 0;
}





