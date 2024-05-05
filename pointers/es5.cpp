# include <cstdlib>
# include <iostream>

using namespace std;


void compareAddresses(int *a, int *b) {
    if (a > b) {
        cout << "a: " << a << "\n" << "b: " << b;
    }
    else {
        cout << "b: " << b << "\n" << "a: " << a;
    }
}

int main () {
    // Depending on which variable is declared first, also the address is smaller than the other (printed before by the compareAddresses)
    int b;
    int a;

    cout << "value of a: ";
    cin >> a;
    cout << "value of b: ";
    cin >> b;

    int *p_a = &a;
    int *p_b = &b;

    compareAddresses(p_a, p_b);
}