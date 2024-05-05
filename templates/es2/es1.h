/*
Implement a vector replacement that operates only on integers, vectorOfTypes (you don't need to
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

# include <cstdlib>
# include <iostream>
# include <cstdlib>
# include <iostream>


using namespace std;


template <typename T>
class vectorOfTypes {

    public:
        vectorOfTypes ();
        vectorOfTypes (int size);
        ~vectorOfTypes ();
        vectorOfTypes& operator= (const vectorOfTypes& other);
        vectorOfTypes (const vectorOfTypes& other);

        T getValue (int index);
        T* setValue (int index, T value);
        T* pushBack (T value);
        T* pushFront (T value);
        void displayVector();

    private:
        T *vector;
        int vSize;
        bool isFull;
        void resize ();
};


/* method definition */

// empty constructor
template <typename T> vectorOfTypes<T>::vectorOfTypes () {
    this -> vSize = 32;
    this -> isFull = false;
    this -> vector = new int[this -> vSize];
    for (int i = 0; i < 32; i++) {
        this -> vector[i] = 0;
    }
}


// non-empty constructor
template<typename T> vectorOfTypes<T>::vectorOfTypes (int size) {
    if (size < 0) {
        cout << "Negative size, taking the modulus as size!" << "\n";
        this -> vSize = -size;
    }
    else if (size == 0) {
        cout << "Zero size, taking the default 32 as size!" << "\n";
        this -> vSize = 32;
    }
    else {
        this -> vSize = size;
    }
    this -> sFull = false;
    this -> vector = new int[this -> vSize];

    for (int i = 0; i < this -> vSize; i++) {
        this -> vector[i] = 0;
    }
}

template<typename T> vectorOfTypes<T>::~vectorOfTypes () {
    cout << "Destructor called!" << "\n";
    delete[] this -> vector;
    this -> vector = NULL;
}

template<typename T> vectorOfTypes<T>& vectorOfTypes<T>::operator= (const vectorOfTypes& other) {

    cout << "Calling the assignment operator!" << "\n";
    // the &other is needed (instead of other) because this is a pointer
    // therefore also the right hand side argument needs to be a pointer
    if (this == &other) {
        return *this;
    }

    // delete necessary because vector is a pointer.
    delete[] vector;
    vector = NULL;


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
template<typename T> vectorOfTypes<T>::vectorOfTypes (const vectorOfTypes& other)
    // default values.
    : vector(NULL)
    , isFull(false)
    , vSize(32)
{
    cout << "Calling the copy constructor!" << "\n";
    this -> vector = new int[other.vSize];
    for (int i = 0; i < other.vSize; i++) {
        vector[i] = other.vector[i];
    }
    this -> vSize = other.vSize;
    this -> isFull = other.isFull;

}

template<typename T> void vectorOfTypes<T>::displayVector () {
    for(int i = 0; i < this -> vSize; i++) {
        cout << "[" << this -> vector[i] << "]" << ", ";
    }
    cout << "\n";
}

template<typename T> T vectorOfTypes<T>::getValue (int index) {
    while (index > this -> vSize || index < 0) {
        cout << "Wrong index, try again (enter the index again): ";
        cin >> index;
    }

    return this -> vector[index];
}

template<typename T> T* vectorOfTypes<T>::setValue (int index, T value) {
    while (index > this -> vSize || index < 0) {
        cout << "Wrong index, try again (enter the index again): ";
        cin >> index;
    }
    this -> vector[index] = value;
    if (index == this -> vSize - 1) {
        this -> isFull = true;
    }
    return this -> vector;
}

template<typename T> void vectorOfTypes<T>::resize () {
    T *tempVec = this -> vector;
    this -> vector = new T[2 * vSize];
    for (int i = 0; i < vSize; i++) {
        this -> vector[i] = tempVec[i];
    }
    for (int i = this -> vSize; i < 2 * this -> vSize; i++) {
        this -> vector[i] = 0;
    }
    // old vector deleted
    delete tempVec;
}

template<typename T> T* vectorOfTypes<T>::pushBack (T value) {
    if (isFull) {
        resize();
        this -> vector[this -> vSize] = value;
        this -> vSize = 2 * this -> vSize;
        // now the vector is not full anymore
        this -> isFull = false;
    }
    else {
        this -> vector[this -> vSize - 1] = value;
    }
    return this -> vector;
}

template<typename T> T* vectorOfTypes<T>::pushFront (T value) {
    int tempSize = this -> vSize;
    if (this -> sFull) {
        resize();
        this -> vSize = 2 * this -> vSize;
        this -> isFull = false;
    }
    for (int i = this -> vSize; i > 0; i--) {

        this -> vector[i] = this -> vector[i - 1];
    }
    this -> vector[0] = value;
    return this -> vector;
}