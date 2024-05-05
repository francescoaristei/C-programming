# include <cstdlib>
# include <iostream>

using namespace std;

void multiplyAndsum (int *a, int *b) {
    int temp = *a;
    *a *= *b;
    *b += temp;
}


int main () {
    int a;
    int b;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    int *p_a = NULL;
    int *p_b = NULL;
    p_a = &a;
    p_b = &b;
    multiplyAndsum(p_a, p_b);
    cout << "a * b: " << a << "\n";
    cout << "a + b: " << b << "\n";
}