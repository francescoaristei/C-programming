# include "calculator.h"
# include <iostream>
# include <cstdlib>

using namespace std;

// procedure to compile, link and then execute the files:
// first compile the files:
// g++ nameofthefile.cpp -c nameofthefile
// once the .o object files are generated, link them together:
// g++ nameofthefile.o nameoftheotherfile.o,....nameoftheotherfiles.o
// the a.exe file is created, execute it with ./a.exe

int main () {
    int a, b;
    cout << "Set a: ";
    cin >> a;
    cout << "Set b: ";
    cin >> b;

    cout << "a + b: " << add(a, b) << "\n";

    cout << "a - b: " << subtract(a, b) << "\n";

    cout << "a * b: " << multiply(a, b) << "\n";

    cout << "a / b" << divide(a, b) << "\n";

}