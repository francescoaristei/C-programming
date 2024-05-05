# include <cstdlib>
# include <iostream>
# include "comparable.h"
# include "highscoreelement.h"
# include <vector>
# include <string>

using namespace std;

void displayComparablesITERATOR (vector<Comparable*> &list) 
{
    for (vector<Comparable*>::iterator itr = list.begin(), end = list.end(); itr != end; ++itr) 
    {
        // itr is a pointer to type *Comparable, so then the pointer to Comparable is dereferenced and then accessed
        // (remember that (*x).method is equal to x -> y). So it is the same as doing *(*x).method
        (*itr) -> toString();
    }
}

void displayComparables (vector<Comparable*> &list) 
{
    for (int i = 0; i < list.size(); i++) {
        list[i] -> toString();
    }
}


vector<Comparable*> sortITERATOR (vector<Comparable*> &comparableList) 
{
    vector<Comparable*> sortedList(0);
    sortedList.push_back(comparableList[0]);

    // insertion sort
    for (vector<Comparable*>::iterator itr = next(comparableList.begin()), end = comparableList.end(); itr != end; ++itr) 
    {
        for (vector<Comparable*>::iterator itr_s = sortedList.begin(), end_s = sortedList.end(); itr_s != end_s; ++itr_s) 
        {
            // if greater, continue
            if ((*itr) -> compare(**itr_s) == 1) {
                if ((itr_s != sortedList.end()) && (next(itr_s) == sortedList.end())) {
                    sortedList.push_back(*itr);
                }
            }
            // if smaller or equal insert before
            else {
                sortedList.insert(itr_s, *itr);
            }
        }
    }
    return sortedList;
}

int main () 
{
    // NOTE: if you initialize with a dimension n != 0 the first n elements are set as nullptr.
    // The pushBack() adds elements in the comparableList but does not replace the nullptr set before!
    vector<Comparable*> comparableList(0);
    int loop = 1;

    while (loop) 
    {
        int score;
        string name;
        cout << "Set a score: ";
        cin >> score;
        //cin.ignore();
        cout << "Set a name: ";
        //getline(cin, name, '\n');
        cin >> name;
        comparableList.push_back(new HighScoreElement(name, score));
        cout << "1 to continue, 0 to exit: ";
        cin >> loop;
    }

    cout << "The vector of Comparable objects is: " << "\n";
    displayComparables(comparableList);

    vector<Comparable*> sortedList = sortITERATOR(comparableList);

    cout << "The sorted vector of Comparable objects is: " << "\n";
    displayComparables(sortedList);
}