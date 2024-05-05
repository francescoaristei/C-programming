# include <iostream>
# include <cstdlib>
# include "htmlParser.h"

using namespace std;

int main (int argc, char *argv[]) {
    cout << "First parse the content of the HTML file named: " << argv[1] << "\n";
    HtmlParser *parser = new HtmlParser();
    map<string, vector<string>> fileContent = parser -> readHTML(argv[1]);
    if (!fileContent.empty()) {
        cout << "Content correctly parsed!";
    }
    cout << "The content of the file is: " << "\n";
    parser -> displayHTML(fileContent);
}