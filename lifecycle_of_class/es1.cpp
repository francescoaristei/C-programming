/*
Implement a vector replacement that operates only on integers, vectorOfInt (you don't need to
use templates like the normal STL). Your class should have the following interface:
• A no-argument constructor that allocates a 32 element vector
• A constructor that takes an initial size as the argument
• A method get, taking an index as returning the value at that index
• A method set, that takes an index and a value, and sets the value at that index
• A method pushback that adds an element to the end of the array, resizing if necessary
• A method pushfront that adds an element to the beginning of the array
• A Copy constructor and assignment operator
Your class should not leak memory; any memory it allocates must be deleted. Try to think carefully
about how your class can be misused, and how you should handle them. What do you do if a user gives
a negative initial size? What about accessing a negative index?
*/


/*
NOTE (copy constructor vs assignment operator): The main purpose of both the concepts in C++ is to assign the value, 
but the main difference between both is copy constructor creates a new object and assigns the value but assignment operator 
does not create a new object, instead it assigns the value to the data member of the same object.
*/

# include <cstdlib>
# include <iostream>
# include "es1.h"


// empty constructor
vectorOfInt::vectorOfInt () {
    vSize = 32;
    isFull = false;
    vector = new int[vSize];
    for (int i = 0; i < 32; i++) {
        vector[i] = 0;
    }
}


// non-empty constructor
vectorOfInt::vectorOfInt (int size) {
    if (size < 0) {
        cout << "Negative size, taking the modulus as size!" << "\n";
        vSize = -size;
    }
    else if (size == 0) {
        cout << "Zero size, taking the default 32 as size!" << "\n";
        vSize = 32;
    }
    else {
        vSize = size;
    }
    isFull = false;
    vector = new int[vSize];

    for (int i = 0; i < vSize; i++) {
        vector[i] = 0;
    }
}

vectorOfInt::~vectorOfInt () {
    // delete vector calls the default destructor of the int* data type
    // which deletes the element.
    // There is no need to delete vSize and isFull because these are primitive data
    // which destructor will be called automatically when the object of vectorOfInt will be destroyed.
    cout << "Destructor called!" << "\n";
    delete[] vector;
    vector = NULL;
}

// given that there is a pointer (int* vector) is better to have a custom assignment operator,
// otherwise if for example something like the following is done:
// vectorOfInt v1;
// vectorOfInt v2;
// vectorOfInt v2 = v1;
// This implies: v2.vector = v1.vector (points to the same address)
// When the destructor of v2 is called, the delete on vector is called, and the memory freed
// When v1 will execute the destructor, the call will be made on a already freed memory area --> crash!
vectorOfInt& vectorOfInt::operator= (const vectorOfInt& other) {

    cout << "Calling the assignment operator!" << "\n";
    // the &other is needed (instead of other) because this is a pointer
    // therefore also the right hand side argument needs to be a pointer
    if (this == &other) {
        return *this;
    }

    // delete necessary because vector is a pointer.
    delete[] vector;
    vector = NULL;
    // NOTE: probably, each time a data type of the class is called, like for example vecotr or vSize, the
    // this -> vector and this -> vSize are implicitly called. Because we are updating vector and vSize on the 
    // calling object.


    // each element of other.vector is copied in the new vector, doing vector = other.vector simply does a shallow copy.
    vector = new int[other.vSize];
    for (int i = 0; i < other.vSize; i++) {
        vector[i] = other.vector[i];
    }
    // vSize and isFull are not pointers, therefore the code is correct.
    vSize = other.vSize;
    isFull = other.isFull;
    return *this;
}

// no return statement, the copy constructor creates a new object from the one passed as parameter, as the name says is a constructor.
vectorOfInt::vectorOfInt (const vectorOfInt& other)
    // default values.
    : vector(NULL)
    , isFull(false)
    , vSize(32)
{
    cout << "Calling the copy constructor!" << "\n";
    vector = new int[other.vSize];
    for (int i = 0; i < other.vSize; i++) {
        vector[i] = other.vector[i];
    }
    vSize = other.vSize;
    isFull = other.isFull;

}

void vectorOfInt::displayVector () {
    for(int i = 0; i < vSize; i++) {
        cout << "[" << vector[i] << "]" << ", ";
    }
    cout << "\n";
}

int vectorOfInt::getValue (int index) {
    while (index > vSize || index < 0) {
        cout << "Wrong index, try again (enter the index again): ";
        cin >> index;
    }

    return vector[index];
}

int* vectorOfInt::setValue (int index, int value) {
    while (index > vSize || index < 0) {
        cout << "Wrong index, try again (enter the index again): ";
        cin >> index;
    }
    vector[index] = value;
    if (index == vSize - 1) {
        isFull = true;
    }
    return vector;
}

void vectorOfInt::resize () {
    int *tempVec = vector;
    vector = new int[2 * vSize];
    for (int i = 0; i < vSize; i++) {
        vector[i] = tempVec[i];
    }
    for (int i = vSize; i < 2 * vSize; i++) {
        vector[i] = 0;
    }
    // old vector deleted
    delete tempVec;
}

int* vectorOfInt::pushBack (int value) {
    if (isFull) {
        resize();
        vector[vSize] = value;
        vSize = 2 * vSize;
        // now the vector is not full anymore
        isFull = false;
    }
    else {
        vector[vSize - 1] = value;
    }
    return vector;
}

int* vectorOfInt::pushFront (int value) {
    int tempSize = vSize;
    if (isFull) {
        resize();
        vSize = 2 * vSize;
        isFull = false;
    }
    for (int i = vSize; i > 0; i--) {

        vector[i] = vector[i - 1];
    }
    vector[0] = value;
    return vector;
}