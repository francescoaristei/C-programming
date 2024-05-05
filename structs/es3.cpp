# include <cstdlib>
# include <iostream>
# include <string>

using namespace std;

const int MAX_SIZE = 20;

struct AddressBook {
    string address;
    string name;
    string phone;
};

AddressBook insertAddress(string name, string address, string phone) {
    AddressBook addressEntry;
    addressEntry.name = name;
    addressEntry.address = address;
    addressEntry.phone = phone;
    return addressEntry;
}

int main() {
    AddressBook addressList[MAX_SIZE];

    string dim;
    cout << "Choose the number of addresses you want to insert in the address book. It needs to be less than " << MAX_SIZE << ".\n";
    getline(cin, dim);
    cout << endl;
    int dimI = stoi(dim);
    int counter = 0;
    while (counter <= dimI) {
        // PROBLEM! IT DOES NOT READ THE NAME THE FIRST TIME, IT GOES DIRECTLY TO READ THE ADDRESS, SOLVE IT.
        string name;
        cout << "Choose a name: ";
        getline(cin, name);
        cout << endl;

        string address;
        cout << "Choose an address: ";
        getline(cin, address);
        cout << endl;

        string phone;
        cout << "Choose a phone: ";
        getline(cin, phone);
        cout << endl;

        addressList[counter] = insertAddress(name, address, phone);
        counter ++;
    }

    bool accessByIndex = true;
    char choice;
    int index;
    while (accessByIndex) {
        cout << "If you want to access a specific address in the address book, type the index of the entry you want to see. \n";
        cin >> index;
        cout << "Address entry selected: " << "(" << addressList[index].address << "," << addressList[index].name << "," << addressList[index].phone << ")" << "\n";
        cout << "Do you want to continue? y/n \n";
        cin >> choice;
        if (choice == 'n') {
            accessByIndex = false;
        }
    }

    cout << "Let us display the addresses. \n";

    for (int i = 0; i < dimI; i++) {
        cout << "Entry n. " << i << "--> (" << "address: " << addressList[i].address << ", name: " << addressList[i].name << ", phone: " << addressList[i].phone << ")" << "\n";
    }
}