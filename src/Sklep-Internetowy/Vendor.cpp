#include "Vendor.h"


Vendor::Vendor(string username, string password, string address, int phone, string email)
	: User(username, password), address(address), phone(phone), email(email) {}

void Vendor::writeProductsToFile(const string& filePath, Product& product)
{
    try {
        ofstream fileOut;
        fileOut.open(filePath, ofstream::app);

        if (!fileOut.is_open())
        {
            cout << "Error while trying to open the file " << filePath << "while writing" << endl;
        }
        else
        {
            cout << "File " << filePath << " opened!\n";
            // writing object of the class for example Clothes 
            fileOut << product << "\n";

        }
        fileOut.close();
    }
    catch (const ofstream::failure& e)
    {
        cout << "Error!\n" << e.what() << endl;
        cout << e.code();
    }
}














