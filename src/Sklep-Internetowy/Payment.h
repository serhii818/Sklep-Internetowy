#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>

using namespace std;

class Payment
{

public:
    class CreditCard
    {
    private:
        int cardNumber;
        int expirationDate;
        int cvv;

    public:
        CreditCard(int cardNum, int expirationDate, int cvv)
            : cardNumber(cardNum), expirationDate(expirationDate), cvv(cvv) {}

        void showPayment();
    };
};

#endif PAYMENT_H
