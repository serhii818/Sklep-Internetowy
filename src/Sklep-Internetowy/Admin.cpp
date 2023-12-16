#include "Admin.h"

vector<Order> Admin::orders;
void Admin::addOrder(Order& order) {
    Admin::orders.push_back(order);
}

void Admin::displayOrders() {
    cout << "All Orders:\n";
    for (Order& order : Admin::orders) {
        order.displayOrderDetails();
        cout << "\n";
    }
}





