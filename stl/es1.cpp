# include <cstdlib>
# include <iostream>
# include <map>


using namespace std;


int main () {

    map<string, string> addressBook;
    int add = 1;

    while (add) {
        string name;
        string email;
        cout << "Type the name: ";
        cin >> name;
        cout << "Type the email: ";
        cin >> email;
        addressBook[name] = email;
        cout << "1 to continue adding, 0 to exit: ";
        cin >> add;
    }

    for (map<string, string>::iterator itr = addressBook.begin(), end = addressBook.end(); itr != end; ++itr) {
        cout << "Name: " << itr -> first << ", Email: " << itr -> second << "\n";
    }

    int remove = 1;
    while (remove) {
        string name;
        cout << "Type the name of the address to remove: ";
        cin >> name;
        addressBook.erase(name);
        cout << "1 to continue, 0 to exit: ";
        cin >> remove;
    }

    for (map<string, string>::iterator itr = addressBook.begin(), end = addressBook.end(); itr != end; ++itr) {
        cout << "Name: " << itr -> first << ", Email: " << itr -> second << "\n";
    }

    int modify = 1;
    while (modify) {
        string name;
        string email;
        cout << "Type the name of the address to modify: ";
        cin >> name;
        map<string, string>::iterator el = addressBook.find(name);
        if (el != addressBook.end()) {
            cout << "Type the email of the address to modify: ";
            cin >> email;
            addressBook[name] = email;
        }
        else {
            cout << "This name is not present in the address book!" << "\n";
        }
        cout << "1 to continue, 0 to exit: ";
        cin >> modify;
    }

    for (map<string, string>::iterator itr = addressBook.begin(), end = addressBook.end(); itr != end; ++itr) {
        cout << "Name: " << itr -> first << ", Email: " << itr -> second << "\n";
    }
}