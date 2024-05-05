# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <map>

// BADLY DONE, EXCERSISE TEXT IS NOT CLEAR!

using namespace std;

const string nonchars = "#<>:();{}.,@[]^*&%$£/\\|!?-_";


void findSeparators(vector<char>& vec, const vector<string>& input) {
    map<char, int> countNonchars;

    for (int i = 0; i < nonchars.length(); i++) {
        countNonchars[nonchars[i]] = 0;
    }

    for (int i = 0; i < nonchars.length(); i++) {
        for (vector<string>::const_iterator itr = input.begin(); itr != input.end(); ++itr) {
            // if an occurrence is found in this line
            if ((*itr).find(nonchars[i]) != string::npos) {
                countNonchars[nonchars[i]] += 1;
                // if the non char has appeared in all the lines
                if (countNonchars[nonchars[i]] == input.size()) {
                    // add it as possible separator
                    vec.push_back(nonchars[i]);
                }
            }
        }
    }
}


int main () {
    vector<string> inputs(0);
    int add = 0;
    while (add < 3) {
        string input;
        cout << "Type some information containing weird separator characters: ";
        getline(cin, input, '\n');
        inputs.push_back(input);
        //cout << "1 to continue adding lines, 0 to stop: ";
        add += 1;
    }
    
    vector<char> separators(0);
    findSeparators(separators, inputs);

    int options = 0;
    cout << "Choose between the following separators: " << "\n";
    for (vector<char>::iterator itr = separators.begin(); itr != separators.end(); ++itr) {
        cout << options << ": " << *itr << "\n";
        options += 1;
    }


    string choice;
    getline(cin, choice, '\n');
    //cin >> choice;
    cout << "Your choice is: " << separators[stoi(choice)] << "\n";

    add = 0;
    while (add < 1) {
        string firstname;
        cout << "Add firstname, secondname and email: " << "\n";
        getline(cin, firstname, separators[stoi(choice)]);
        string secondname;
        getline(cin, secondname, separators[stoi(choice)]);
        string email ;
        getline(cin, email, separators[stoi(choice)]);
        cout << "Firstname: " << firstname << ", Secondname: " << secondname << ", Email: " << email << "\n";
        //cout << "1 to continue adding lines, 0 to stop: ";
        add += 1;
        //cin >> add;
    }
};
        string secondname;