# include <cstdlib>
# include <iostream>
# include "function_dec.h"
# include "struct_dec.h"

using namespace std;

/*

When there are more files and some files include other files there are two possibilities:
- Directly create the executable: g++ main.cpp function_def.cpp -o main creates the main.exe executable. To execute: ./main
  NOTE: This can be done only with the file containing the main function (main.cpp in this case)
- First compile the files which do not have the main() function, then compile the file with the main function and then link them together:
  g++ function_def.cpp -c function_def
  g++ main.cpp -c main
  g++ main.o function_def.o --> the executable main.exe is created --> execute it with ./a.exe


INCLUDE GUARDS:
In this case, main.cpp includes both function_dec.h and struct_dec.h
function_dec.h includes struct_dec.h, therefore, the pre processor will "copy paste" the code
of the struct_dec.h in the main.cpp two times which gives errors from the linker.
To avoid this, in the struct_dec.h i can do:
ifndef STRUCT_DEC_H
define STRUCT_DEC_H
...code of struct_dec.h....
endif
This way, when the function_dec.h is included in the main.cpp, its code is loaded, the #include struct_dec.h
in the function_dec.h is loaded as well, which means that the preprocessor will define the STRUCT_DEC_H. Therefore,
when the # include struct_dec.h in the main.cpp is done, at this point, the STRUCT_DEC.H is already defined, therefore
the ifndef yields false, and the code is not "copy pasted" twice in the main, solving the multiple definition problem.
A good explanation at: https://www.youtube.com/watch?v=pF1_fXz5zN0
*/

int main () {
    Node *root = NULL;
    int add = 1;

    while (add) {
        int value;
        cout << "Set the value of the Node: ";
        cin >> value;
        root = addNode(root, value);
        displayTree(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    cout << "Display the nodes in sorted order: " << "\n";
    sortedOrder(root);

    cout << "\n";

    cout << "Display the nodes in reversed sorted order: " << "\n";
    reversedSortedOrder(root);

    freeMemory(root);
    add = 1;

    while (add) {
        int value;
        cout << "Set the value of the node: ";
        cin >> value;
        root = addNode(root, value);
        displayNodes(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    cout << "Print the number of nodes: " << countNodes(root);

    freeMemory(root);

    add = 1;

    while (add) {
        int value;
        cout << "Set the value of the node: ";
        cin >> value;
        root = addNode(root, value);
        displayNodes(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    bool balanced = true;

    ifBalanced(root, 0, &balanced);

    cout << "Is the tree balanced? ";

    if (balanced) {
        cout << "Yes!";
    }
    else {
        cout << "No!";
    }
    
    freeMemory(root);

    add = 1;

    while (add) {
        int value;
        cout << "Set the value of the node: ";
        cin >> value;
        root = addNode(root, value);
        displayNodes(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    cout << "Is the tree sorted? ";
    if (checkSorted(root)) {
        cout << "Yes!";
    }
    else {
        cout << "No!";
    }
    freeMemory(root);

    Address *rootA = NULL;
    add = 1;

    while (add) {
        string name;
        string email;
        cout << "Set the name: ";
        cin >> name;
        cout << "Set the email: ";
        cin >> email;
        rootA = addNode(rootA, name, email);
        displayAddresses(rootA, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    int remove = 1;

    while (remove) {
        string name;
        cout << "Set the name of the address to remove: ";
        cin >> name;
        rootA = removeNode(rootA, name);
        displayAddresses(rootA, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> remove;
    }

    int modify = 1;

    while (modify) {
        string name;
        string email;
        cout << "Set the name of the email to modify: ";
        cin >> name;
        cout << "Type the new email: ";
        cin >> email;
        updateEmail(rootA, name, email);
        displayAddresses(rootA, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> modify;
    }

    int searchAddr = 1;

    while (searchAddr) {
        string name;
        cout << "Set the name of the email to search: ";
        cin >> name;
        Address *node = search(rootA, name);
        if (node) {
            cout << "Name on the address: " << node -> name << "\n";
            cout << "Email on the address: " << node -> email << "\n";
        }
        else {
            cout << "Address not present!" << "\n";
        }
        cout << "1 to continue, 0 to exit: ";
        cin >> searchAddr;
    }

    freeMemory(rootA);
}
