#ifndef CONSUMER_H
#define CONSUMER_H

#include<iostream>
#include<fstream>
#include<sstream>

#include "User.h"
#include "Cart.h"
#include "Order.h"
#include "Admin.h"
#include "Tools.h"




class Consumer : public User {
public:

    
    
    Consumer(string username, string password, string address, int phone, string email);
    Consumer(string data);
    Consumer() = default;

    void displayInfo() override;
    bool makePurchase();

    friend class Admin;
    friend std::istream& operator>>(std::istream& is, Consumer& c);
    friend std::ostream& operator<<(std::ostream& os, const Consumer& c);

    void setCreditNumber(int number) {
        Consumer::creditCard.setNumber(number);
    }
    void setExpirationDate(int expDate) {
        this->creditCard.setExpirationDate(expDate);
    }
    void setCvv(int cvv) {
        this->creditCard.setCvv(cvv);
    }
    void saveToFile(string path);
    void addProductToCart();
    void displayCart();

    // operator = for class Consumer - Consumer a = Consumer b
    Consumer& operator = (const Consumer &that)
    {
        this->password = that.password;
        this->username = that.username;
        this->address = that.address;
        this->email = that.email;
        this->phone = that.phone;
        this->creditCard = that.creditCard;

        return *this;
    }

private:
    // Przyklad agregacji klasy CreditCard do klasy Consumer
    class CreditCard
    {
    private:
        int cardNumber;
        int expirationDate;
        int cvv;

    public:

        // operator = dla CreditCard
        CreditCard& operator = (const CreditCard& that)
        {
            this->cardNumber = that.cardNumber;
            this->expirationDate = that.expirationDate;
            this->cvv = that.cvv;

            return *this;
        }

        CreditCard() = default;

        void makePayment() {
            cout << "Successful payment with card:\n"
                << "Credit Card Number: " << cardNumber << "\n"
                << "Expiration Date: " << expirationDate << "\n"
                << "CVV: " << cvv << "\n";
        }
        void setNumber(int number) {
            this->cardNumber = number;
        }
        void setExpirationDate(int expDate) {
            this->expirationDate = expDate;
        }
        void setCvv(int cvv) {
            this->cvv = cvv;
        }
        int getCardNumber() { return cardNumber; }
        int getExpirationDate() { return expirationDate; }
        int getCvv() { return cvv; }

        friend std::istream& operator>>(std::istream& is, Consumer& c);
        friend std::ostream& operator<<(std::ostream& os, const Consumer& c);
    };
    CreditCard creditCard;
    string address;
    int phone;
    string email;
    Cart cart;
    
};

#endif 


