# include <cstdlib>
# include <iostream>

using namespace std;

void setNameSurnamePointers (string *name, string *surname) {
    cout << "Type the name: ";
    cin >> *name;
    cout << "Type the surname: ";
    cin >> *surname;
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


    // On lines 28, 29 the &name and &surname are passed to the pointers.
    // The setNameSurnamePointers function takes as input string *name, string *surname (two pointers).
    // So doing this is exactly the same as using the pointers (is like passing directly &name, &surname instead of assigning 
    // them to the pointers and then pass the pointers).
    cout << "Name: " << name << "\n";
    cout << "Surname: " << surname << "\n";

}


