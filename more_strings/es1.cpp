# include <cstdlib>
# include <iostream>
# include <string>


using namespace std;

int main () {
    string haystack;
    string needle;
    cout << "Haystack: ";
    getline(cin, haystack, '\n');
    cout << "Needle: ";
    getline(cin, needle, '\n');

    int counter = 0;
    for (int i = haystack.find(needle, 0); i != string::npos; i = haystack.find(needle, i)) {
        counter += 1;
        i += 1;
    }

    cout << "The number of occurrences of " << needle << " into " << haystack << " is: " << counter;
}