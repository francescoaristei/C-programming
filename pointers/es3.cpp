# include <cstdlib>
# include <iostream>

using namespace std;

void setNameSurnamePointers (string *name, string *surname) {
    cout << "Type the name: ";
    cin >> *name;

    if (surname == NULL) {
        cout << "Type the surname: ";
        cin >> *surname;
    }
}

void setNameSurnameReference (string& name, string& surname) {
    cout << "Type the name: ";
    cin >> name;
    cout << "Type the surname: ";
    cin >> surname;
}

int main () {
    string *pName = NULL;
    string *pSurname = NULL;
    string name;
    string surname;

    pName = &name;
    pSurname = &surname;
    setNameSurnamePointers(pName, pSurname);

    cout << "Name: " << name << "\n";
    cout << "Surname: " << surname << "\n";

    string &nameRef = name;
    string &surnameRef = surname;
    setNameSurnameReference(nameRef, surnameRef);

    cout << "Name: " << name << "\n";
    cout << "Surname: " << surname << "\n";


    setNameSurnamePointers(&name, &surname);

    cout << "Name: " << name << "\n";
    cout << "Surname: " << surname << "\n";

}
