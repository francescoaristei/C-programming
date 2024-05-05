# include <fstream>
# include <iostream>
# include "file_transformer.h"
# include <functional>
# include <chrono>

using namespace std;

void transformFile (string fileName) {
    fstream file(fileName, ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Could not open the file, exiting!" << "\n";
        return;
    }

    int8_t number;
    vector<int8_t> numToWrite;
    while (file.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        int8_t newNumber = number % 5;
        numToWrite.push_back(newNumber);
    }
    // needed in order to write
    file.clear();

    // restart from the beginning
    file.seekg(0, ios::beg);
    for (int i = 0; i < numToWrite.size(); i++) {
        file.write(reinterpret_cast<char*>(&numToWrite[i]), sizeof(numToWrite[i]));
    }
    file.close();
}

void printNumbers (string fileName) {
    fstream file(fileName, ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Could not open the file, exiting!" << "\n";
        return;
    }

    int8_t num;
    cout << "The numbers are: ";
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        cout << num << " , ";
    }
    cout << "\n";

    file.seekg(0, ios::beg);
    file.close();
}

int main (int argc, char* argv[]) {
    string fileName = argv[1];

    fstream file(fileName, ios::binary | ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Could not open the file, exiting!" << "\n";
        return -1;
    }

    // write the file with some random number
    int loop = 1;

    while (loop) {
        int8_t number;
        cout << "Set an 8 bit integer number: ";
        cin >> number;
        file.write(reinterpret_cast<char*>(&number), sizeof(number));
        cout << "1 to continue, 0 to exit: ";
        cin >> loop;
    }

    // go back to starting position
    file.seekg(0, ios::beg);

    printNumbers(fileName);

    ThreadPool tp(2);
    tp.pushTask(bind(&transformFile, fileName));
    tp.pushTask(bind(&transformFile, fileName));

    this_thread::sleep_for(chrono::seconds(5));

    file.seekg(0, ios::beg);
    printNumbers(fileName);

}