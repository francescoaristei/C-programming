# include <cstdlib>
# include <iostream>
# include "comparable.h"
# include "caseInsensitive.h"
# include "reverseOrder.h"
# include <vector>
# include <string>

using namespace std;


int main () 
{

    int loop = 1;
    Comparable *caseInsensitive = new CaseInsensitive();
    Comparable *reverseOrder = new ReverseOrder();

    while (loop) 
    {
        string a;
        string b;
        cout << "Set string a: ";
        getline(cin, a, '\n');
        cout << "Set string b: ";
        getline(cin, b, '\n');
        cout << "The alphabetical order irrespecitve of the case is: ";
        if (caseInsensitive -> compare(a, b) == 1) {
            cout << b << " then " << a << "\n";
        }
        else if (caseInsensitive -> compare(a, b) == 0) {
            cout << a << " same as " << b << "\n";
        }
        else {
            cout << a << " then " << b << "\n";
        }
        cout << "The reversed alphabetical order is: ";
        if (reverseOrder -> compare(a, b) == 1) {
            cout << b << " then " << a << "\n";
        }
        else if (reverseOrder -> compare(a, b) == 0) {
            cout << a << " same as " << b << "\n";
        }
        else {
            cout << a << " then " << b << "\n";
        }
        cout << "1 to continue, 0 to exit: ";
        cin >> loop;
        cin.ignore();
    }
}