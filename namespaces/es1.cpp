# include <cstdlib>
# include <iostream>
# include "es1.h"


// empty constructor
jumpingcpp::vectorOfInt::vectorOfInt () {
    vSize = 32;
    isFull = false;
    vector = new int[vSize];
    for (int i = 0; i < 32; i++) {
        vector[i] = 0;
    }
}


// non-empty constructor
jumpingcpp::vectorOfInt::vectorOfInt (int size) {
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

jumpingcpp::vectorOfInt::~vectorOfInt () {
    cout << "Destructor called!" << "\n";
    delete[] vector;
    vector = NULL;
}

jumpingcpp::vectorOfInt& jumpingcpp::vectorOfInt::operator= (const vectorOfInt& other) {

    cout << "Calling the assignment operator!" << "\n";
    if (this == &other) {
        return *this;
    }

    delete[] vector;
    vector = NULL;
    vector = new int[other.vSize];
    for (int i = 0; i < other.vSize; i++) {
        vector[i] = other.vector[i];
    }
    vSize = other.vSize;
    isFull = other.isFull;
    return *this;
}

jumpingcpp::vectorOfInt::vectorOfInt (const vectorOfInt& other)
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

void jumpingcpp::vectorOfInt::displayVector () {
    for(int i = 0; i < vSize; i++) {
        cout << "[" << vector[i] << "]" << ", ";
    }
    cout << "\n";
}

int jumpingcpp::vectorOfInt::getValue (int index) {
    while (index > vSize || index < 0) {
        cout << "Wrong index, try again (enter the index again): ";
        cin >> index;
    }

    return vector[index];
}

int* jumpingcpp::vectorOfInt::setValue (int index, int value) {
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

void jumpingcpp::vectorOfInt::resize () {
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

int* jumpingcpp::vectorOfInt::pushBack (int value) {
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

int* jumpingcpp::vectorOfInt::pushFront (int value) {
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