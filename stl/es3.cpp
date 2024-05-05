# include <iostream>
# include <cstdlib>
# include <map>

using namespace std;


int main () {
    map<string, string> userData;

    int add = 1;
    while (add) {
        string username;
        string password;
        cout << "Type the username of the user: ";
        cin >> username;
        if (userData.find(username) != userData.end()) {
            cout << "User already registered, change username: ";
            cin >> username;
        }
        cout << "Type a password for the user: ";
        cin >> password;
        userData[username] = password;
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    int login = 1;
    int notLoggedIn = 1;
    string username;
    string password;
    while (login) {
        if (notLoggedIn) {
            cout << "Type the username: ";
            cin >> username;
            cout << "Type the password: ";
            cin >> password;
            if (userData[username] == password) {
                cout << "Login successfull." << "\n";
                notLoggedIn = 0;
            }
            else {
                cout << "Username or password are incorrect." << "\n";
            }
        }
        else {
            int option;
            cout << "1 to change password, 0 to log out: ";
            cin >> option;
            if (option) {
                string newPassword;
                cout << "Type the new password: ";
                cin >> newPassword;
                userData[username] = newPassword;
                notLoggedIn = 0;
            }
            else {
                cout << "Logged out" << "\n";
                notLoggedIn = 1;
            }
        }
    }
}