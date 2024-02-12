#include "Admin.h"

// exception class

class ProjException : public exception
{
public:
    ProjException(const char* message, int dataInf) : exception(message)
    {
        this->dataInf = dataInf;
    }
    int getDataInfo()
    {
        return this->dataInf;
    }

private:
    int dataInf;
};


vector<Order> Admin::orders;
vector<User> Admin::listaUsers;

void Admin::addOrder(Order& order) 
{
    Admin::orders.push_back(order);
}

void Admin::banUser(string username)
{
    ofstream file("Banned.txt");
    file << username << '\n';
    file.close();
}

void Admin::displayOrders() 
{
    cout << "\nAll Orders:\n";
    for (Order& order : Admin::orders)
    {
        order.displayOrderDetails();
        cout << "\n";
    }
}
Admin::Admin(string username, string password, string email) 
    : User(username, password), email(email) {}

Admin::Admin(string data) {
    istringstream iss(data);
    iss >> username >> password >> email;
}


//  bubble sort

void Admin::sortOrders()
{
    try {
        int size = (int) orders.size();
        if (size == 0)
        {
            throw ProjException("\nOrders number is too small!", size);
        }
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size - i - 1; j++)
            {
                if (orders[j].getOrderId() > orders[j + 1].getOrderId())
                {
                    Order temp = orders[j];
                    orders[j] = orders[j + 1];
                    orders[j + 1] = temp;
                }
            }
        }
    }
    catch (const std::out_of_range& e)
    {
        cerr << "\nError: " << e.what() << std::endl;
    }
    catch (ProjException& e)
    {
        cout << e.what() << endl;
        cout << "\nData causing troubles: " << e.getDataInfo() << endl;
    }
    catch (const std::exception& e) {
        cerr << "\nError: " << e.what() << std::endl;
    }
    catch (...)
    {
        cout << "\nSomething went wrong...\n";
    }
}

void Admin::displayInfo() {
    cout << username << endl;
    cout << email << endl;
}






