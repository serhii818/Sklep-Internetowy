// Cart.h
#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"
using namespace std;

// kolejka FIFO - DLA KOLEJNOSCI W SPRZEDAZY ORDEROW
template <typename T>
class Fifo {
private:
    T queue<T> data;

public:

    Fifo(const Fifo& other) : data(other.data) {}

    void add(T object) {
        data.push(object);
    }

    void remove() {
        if (!isEmpty()) {
            data.pop();
        }
        else {
            cout << "FIFO is empty" << std::endl;
        }
    }

    T front() const {
        if (!isEmpty()) {
            return data.front();
        }
        else {
            throw std::out_of_range("FIFO is empty");
        }
    }

    void showAll() {
        std::queue<T> temp = data;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    int size() const {
        return data.size();
    }

    Fifo& operator=(const Fifo& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    bool isEmpty() const {
        return data.empty();
    }
};

class Cart {
public:
    void addItem(Product* product);
    void displayCart();
    double calculateTotalPrice();
    Fifo<Product*> getItems();
    

private:
    Fifo<Product*> items;
    
};

#endif CART_H

