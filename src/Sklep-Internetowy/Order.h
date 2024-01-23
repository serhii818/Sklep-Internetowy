#ifndef ORDER_H
#define ORDER_H
#pragma once

#include <vector>
#include "Product.h"
#include "Cart.h"
#include "Consumer.h"

class Consumer;
class Product;
class Cart;

template <typename T>
class Safe {
private:
    vector<T> data;

public:



    void add(T object) {
        this->data.push_back(object);
    }

    void remove() {
        if (!isEmpty()) {
            this->data.pop_back();
        }
        else {
            cout << "Nie ma danych" << std::endl;
        }
    }

    T show() {
        return this->data.back();
    }

    void showAll() {
        for (const T& obj : data) cout << obj << " "; cout << endl;
    }

    bool isEmpty() const {
        return this->data.empty();
    }

    ~Safe() {
        this->data.clear();
    }

};

enum class OrderStatus
{
    Pending,
    Completed,
    Unknown
};

class Order {
public:
    Order(Consumer* consumer, Cart cart);

    void displayOrderDetails();
    int getOrderId();
    void addItem(Product product);
    void showAll();
    double calculateTotalPrice();
    Safe<Product> getItems();
    static int orderCount;

protected:
    Consumer* consumer;
    vector<Product*> products;
    OrderStatus status;
    int orderId;
    Safe<Product> items;
};

#endif 