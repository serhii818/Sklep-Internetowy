#include "Vendor.h"


Vendor::Vendor(string username, string password, string address, int phone, string email)

	: User(username, password), address(address), phone(phone), email(email) {}
std::istream& operator>>(std::istream& is, Vendor& v)
{
    is >> v.username >> v.password >> v.address >> v.email >> v.phone;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Vendor& v)
{
    os << v.username << " " << v.password << " " << v.address << " " << v.email << " " << v.phone << '\n';
    return os;
}

Vendor::Vendor(string data) {
    istringstream iss(data);
    iss >> *this;
}

void Vendor::displayInfo()
{
    cout << "\nUsername: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
}


