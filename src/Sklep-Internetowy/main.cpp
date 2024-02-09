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

#include<sstream>
using namespace std;


int main() {

    auto start = std::chrono::high_resolution_clock::now();

    Store store;
    store.startLoop();


    return 0;
}






