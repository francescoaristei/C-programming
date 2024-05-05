# include <cstdlib>
# include <iostream>

// needed to use getline
# include <string>

using namespace std;

struct AddressBook {
    string name;
    string address;
    string phone;
};

AddressBook initializeAddressBook(AddressBook addressBook) {
    addressBook.name = "Example Name";
    addressBook.address = "Example Address";
    addressBook.phone = "Example Phone";
    return addressBook;
}

int main() {
    string address;
    string name;
    string phone;
    AddressBook addressBook;
    addressBook = initializeAddressBook(addressBook);
    cout << "Insert name, address and phone number associated to the address." << "\n";
    cout << "Address: " << "\n";
    // To take the whole line, otherwise, cin stops reading the user input at the first space: " "
    getline(cin, address);
    cout << "Name:" << "\n";
    getline(cin, name);
    cout << "Phone:" << "\n";
    getline(cin, phone);    
    addressBook.name = name;
    addressBook.address = address;
    addressBook.phone = phone;
}