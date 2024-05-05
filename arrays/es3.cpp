# include <cstdlib>
# include <iostream>
# include <ctime>


using namespace std;

// Write a program that detects if a list is sorted or not, and if it is not sorted, sort it.

bool is_sorted(int array[], int size) {
    bool is_sorted = true;
    int i = 0;
    int j = 1;

    while (j < size) {
        if (array[i] > array[j]) {
            is_sorted = false;
            break;
        } 
        i ++;
        j ++;
    }
    return is_sorted;
}

int get_index_min(int array[], int size, int start_index) {
    int index = start_index;
    for (int i = start_index + 1; i < size; i++) {
        if (array[i] < array[index]) {
            index = i;
        }
    }
    return index;
}

// void because the array is passed by reference and modified in place
void sort(int array[], int size) {
    // insertion sort implementation
    for (int i = 0; i < size; i ++) {
        // get min element in the subarray
        int min_index = get_index_min(array, size, i);

        // exchange first element of subarray with min element in the subarray
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
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
    int size = 10;
    int array[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        // compute the rest on the division by 100 to keep the numbers low
        array[i] = rand() % 100;
    }


    cout << "Check if the array is sorted: " << "\n";

    if (is_sorted(array, size)) {
        cout << "Array already sorted!" << "\n";
        cout << "The array is: " << "\n";
        display_array(array, size);
    }
    else {
        cout << "Array not sorted, sort it." << "\n";
        cout << "The array before the sorting :" << "\n";
        display_array(array, size);

        sort(array, size);
        cout << "\n";
        cout << "The array after having sorted it: " << "\n";
        display_array(array, size);
    }
}
