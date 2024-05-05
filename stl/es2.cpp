# include <cstdlib>
# include <iostream>
# include <vector>

using namespace std;

int main () {
    vector<int> scoresList(0);
    int add = 1;
    while (add) {
        int value;
        if (scoresList.empty()) {
            cout << "Enter the first score in the game: ";
            cin >> value;
            scoresList.push_back(value);
        }
        else {
            bool addLast = true;
            cout << "Enter the score: ";
            cin >> value;
            for (vector<int>::iterator itr = scoresList.begin(), end = scoresList.end(); itr != end; ++itr) {
                if (value > *itr) {
                    scoresList.insert(itr, value);
                    addLast = false;
                    break;
                }
            }
            // if last element
            if (addLast) {
                scoresList.push_back(value);
            }
        }
        int counter = 0;
        for (vector<int>::iterator itr = scoresList.begin(), end = scoresList.end(); itr != end; ++itr) {
            cout << "Element " << counter << "-th" << ": " << *itr << "\n";
            counter ++;
        }
        cout << "------------------------------" << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }
}