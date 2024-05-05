# include <cstdlib>
# include <iostream>
# include <ctime>

using namespace std;

// program that takes in 50 values, prints the highest, lowest, the average and all the 50 values, one per line

int get_highest(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;

}

int get_lowest(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

int get_average(int array[], int size) {
    int avg = 0;
    for (int i = 0; i < size; i++) {
        avg += array[i];
    }
    avg = avg / 50;
    return avg;
}

void display_array(int array[], int size) {
    cout << "{";
    for ( int i = 0; i < size; i++ ) {
        if ( i != 0 ) {
            cout << ", ";
        }
        cout << array[ i ];
    }
    cout << "}";
}

int main () {

    int size = 50;
    int array[50];
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        // compute the rest on the division by 100 to keep the numbers low
        array[i] = rand() % 100;
    }
    cout << "The highest element in the array is: " << get_highest(array, size) << "\n";
    cout << "The lowest element in the array is: " << get_lowest(array, size) << "\n";
    cout << "The average of all the elements in the array is: " << get_average(array, size) << "\n";
    cout << "Now let display all the elements of the array: " << "\n";
    display_array(array, size);
    
}