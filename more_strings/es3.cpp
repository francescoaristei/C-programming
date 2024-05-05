# include <iostream>
# include <cstdlib>
# include <string>
# include <map>
# include <vector>

using namespace std;


void displayHTML (const map<string, vector<string>>& fields){
    cout << "<html>" << "\n";
    cout << "     " << "<body>" << "\n";
    for (map<string, vector<string>>::const_iterator itr = fields.begin(); itr != fields.end(); ++itr) {
        if (itr -> first == "i") {
            for (vector<string>::const_iterator itr_v = itr -> second.begin(); itr_v != itr -> second.end(); ++itr_v) {
                cout << "          " << "<i>" << *itr_v << "</i>" << "\n";
            }
        }
        if (itr -> first == "b") {
            for (vector<string>::const_iterator itr_v = itr -> second.begin(); itr_v != itr -> second.end(); ++itr_v) {
                cout << "          " << "<b>" << *itr_v << "</b>" << "\n";
            }
        }
        if (itr -> first == "a") {
            for (vector<string>::const_iterator itr_v = itr -> second.begin(); itr_v != itr -> second.end(); ++itr_v) {
                cout << "          " << "<a>" << *itr_v << "</a>" << "\n";
            }
        }
    }
    cout << "</html>" << "\n";
    cout << "     " << "</body>" << "\n";
}

int main () {
    map<string, vector<string>> htmlElements;
    cout << "Type HTML text: " << "\n";
    string text;
    getline(cin, text, '\n');

    // extract text inside html tags
    int html_i = text.find("<html>", 0);
    int html_j = text.find("</html>", 0);
    int length_html = html_j - html_i;
    text = text.substr(html_i + 6, length_html - 6);
    cout << text << "\n";


    // remove head
    int head_i = text.find("<head>", 0);
    int head_j = text.find("</head>", 0);
    text = text.substr(head_j + 7);
    cout << text << "\n";


    // extract text inside body
    int body_i = text.find("<body>", 0);
    int body_j = text.find("</body>", 0);
    int length_body = body_j - body_i;
    text = text.substr(body_i + 6, length_body - 6);
    cout << text << "\n";


    // extract <i> tags
    int i_i = 0; 
    int i_j = 0;
    for (i_i = text.find("<i>", 0), i_j = text.find("</i>", 0); i_j != string::npos; i_i = text.find("<i>", i_i), i_j = text.find("</i>", i_j)) {
        int length_i = i_j - i_i;
        htmlElements["i"].push_back("_" + text.substr(i_i + 3, length_i - 3) + "_");
        i_i += 1;
        i_j += 1;
    }

    // extract <b> tags
    int b_i = 0; 
    int b_j = 0;
    for (b_i = text.find("<b>", 0), b_j = text.find("</b>", 0); b_j != string::npos; b_i = text.find("<b>", b_i), b_j = text.find("</b>", b_j)) {
        int length_b = b_j - b_i;
        htmlElements["b"].push_back("*" + text.substr(b_i + 3, length_b - 3) + "*");
        b_i += 1;
        b_j += 1;

    }

    // extract <a> tags
    int a_i = 0; 
    int a_j = 0;
    for (a_i = text.find("<a href=linkurl>", 0), a_j = text.find("</a>", 0); a_j != string::npos; a_i = text.find("<a>", a_i), a_j = text.find("</a>", i_j)) {
        int length_a = a_j - a_i;
        htmlElements["a"].push_back("<linkurl>" + text.substr(a_i + 16, length_a - 16) + "<linkurl>");
        a_i += 1;
        a_j += 1;
    }

    displayHTML(htmlElements);
}