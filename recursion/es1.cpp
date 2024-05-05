// pow recursive algorithm

# include <cstdlib>
# include <iostream>

using namespace std;

int power (int base, int exponent) {
    if (exponent == 1) {
        return base;
    }

    return base * power(base, exponent - 1);
}


int main () {
    int base;
    int exponent;
    cout << "Set base: ";
    cin >> base;
    cout << "Set exponent: ";
    cin >> exponent;

    int result = power(base, exponent);
    cout << "The result is: " << result;
}