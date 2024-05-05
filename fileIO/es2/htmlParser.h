

# ifndef HTMLPARSER
# define HTMLPARSER

# include <vector>
# include <map>
# include <iostream>
# include <fstream>

using namespace std;

class HtmlParser {
    public:
        void displayHTML (const map<string, vector<string>>& fields);
        map<string, vector<string>> fillMap (const map<string, vector<vector<streampos>>>& indexes, const string& fileName);
        map<string, vector<string>> readHTML (const string& fileName);

};
# endif