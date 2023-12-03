#include "Order.h"
#include <iostream>

//using namespace std;

Order::Order(Consumer* consumer, Cart cart, Payment::CreditCard payment)
    : consumer(consumer), payment(payment) {
    for (Product item : cart.getItems()) {
        products.push_back(item);
    }
}

void Order::displayOrderDetails() {
    cout << "Order Details:\n";
    consumer.displayInfo();
    cout << "Products in the order:\n";
    for (Product product : products) {
        product.displayInfo();
    }
    payment.showPayment();


  
}
