# include <cstdlib>
# include <iostream>

using namespace std;


void displayArrayForward (int *array, int dim) {
    cout << "[";
    for (int i = 0; i < dim; i++) {
        cout << array[i];
        if (i < dim - 1) {
            cout << ",";
        }
    }
    cout << "]";
}

void displayArrayBackward (int *array, int dim) {
    if (dim == 0) {
        cout << array[dim];
        cout << "]";
        return;
    }
    cout << array[dim] << ",";
    displayArrayBackward(array, dim - 1);
}


int main () {
    int dim;
    cout << "Set the array dim: ";
    cin >> dim;
    int *array = new int[dim];
    for (int i = 0; i < dim; i++) {
        cout << "Set the " << i << "-th element: ";
        cin >> array[i];
    }
    cout << "The array is: ";
    displayArrayForward(array, dim);
    cout << "\n";
    cout << "The reversed array is: [";
    displayArrayBackward(array, dim - 1);
}