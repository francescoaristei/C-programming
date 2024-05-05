/*
Write a program that reads in HTML text that the user types in (don’t worry, we’ll cover how to
read from a file later). It should support the following HTML tags: <html>, <head>, <body>, <b>,
<i>, and <a>. Each HTML tag has an open tag, e.g. <html>, and a closing tag which has a forwardslash at the start: </html>. 
Inside the tag is text that is controlled by that tag: <b>text to be
bolded</b> or <i>text to be italicized</i>. The <head> </head> tags control text that is
metadata, and the <body></body> tags surround text that is to be displayed. <a> tags are used
for hyperlinks, and have an URL in the following format: <a href=URL>text</a>.
Once your program has read in some HTML, it should simply ignore <html>. It should remove
any text from the <head> section so that it doesn't show up when you output it. It should then
display all text in the body, modifying it so that any text between a <b> and a </b> will show up
with asterisks (*) around it, any text inside <i> and </i> will show up with underscores (_)
around it, and any text with a <a href=linkurl>link text</a> tag shows up as link text (linkurl).
*/

// ALMOST WORKS, readHTML is bad, should be rewritten using a stack data structure to enforce HTML structure (as in es3/xmlParser.cpp) !!   

# include <iostream>
# include <cstdlib>
# include <string>
# include <map>
# include <vector>
# include <fstream>
# include "htmlParser.h"

using namespace std;


void HtmlParser::displayHTML (const map<string, vector<string>>& fields){
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

map<string, vector<string>> HtmlParser::fillMap (const map<string, vector<vector<streampos>>>& indexes, const string& fileName) {
    fstream file(fileName, ios::in | ios::out);

    map<string, vector<string>> emptyMap;

    if (!file.is_open()) {
        cout << "Could not open the file!" << "\n";
        return emptyMap;
    }

    // NOTE: in maps if you access with operator [] (e.g map["key"]) if the key does not exist, the operator 
    // creates it for you, which is not correct when working with a CONSTANT map, hence, use .at()

    map<string, vector<string>> result;
    // read <b>
    vector<vector<streampos>> b = indexes.at("b");
    for (vector<vector<streampos>>::iterator itr = b.begin(), end = b.end(); itr != end; ++itr) {
        streampos beginIndex = (*itr)[0];
        streampos endIndex = (*itr)[1];
        file.seekg(beginIndex);
        string line;
        string text = "";
        while (file >> line) {
            if (file.tellg() == endIndex) {
                break;
            }
            text += line;
        }
        result["b"].push_back(text);
    }

    file.clear();

    // read <i>
    vector<vector<streampos>> i = indexes.at("i");
    for (vector<vector<streampos>>::iterator itr = i.begin(), end = i.end(); itr != end; ++itr) {
        streampos beginIndex = (*itr)[0];
        streampos endIndex = (*itr)[1];
        file.seekg(beginIndex);
        string line;
        string text = "";
        while (file >> line) {
            if (file.tellg() == endIndex) {
                break;
            }
            text += line;

        }
        result["i"].push_back(text);
    }

    file.clear();

    // read <a>
    vector<vector<streampos>> a = indexes.at("a");
    for (vector<vector<streampos>>::iterator itr = a.begin(), end = a.end(); itr != end; ++itr) {
        streampos beginIndex = (*itr)[0];
        streampos endIndex = (*itr)[1];
        file.seekg(beginIndex);
        string line;
        string text = "";
        while (file >> line) {
            if (file.tellg() == endIndex) {
                break;
            }
            text += line;
        }
        result["a"].push_back(text);
    }

    // file close
    file.close();
    return result;
}


map<string, vector<string>> HtmlParser::readHTML (const string& fileName) {
    map<string, vector<vector<streampos>>> textIndexes;
    fstream file(fileName, ios::in | ios::out);

    // to return in case of error (NOT GOOD PRACTICE)
    map<string, vector<string>> emptyMap;
    if (!file.is_open()) {
        cout << "Could not open the file!" << "\n";
        return emptyMap;
    }
    string line;
    bool notValidHTML = false;
    string errorMessage;

    // to save starting and ending position of the different sections
    streampos startHTML;
    streampos startHEAD;
    streampos startBODY;
    streampos endHTML;
    streampos endHEAD;
    streampos endBODY;
    
    // starting and ending positions of each text section
    streampos startB;
    streampos endB;
    streampos startI;
    streampos endI;
    streampos startA;
    streampos endA;

    bool enterHTML = false;
    bool enterHEAD = false;
    bool enterBODY = false;
    bool exitHTML = false;
    bool exitBODY = false;
    bool exitHEAD = false;
    bool enterA = false;
    bool enterB = false;
    bool enterI = false;
    bool exitA = false;
    bool exitB = false;
    bool exitI = false;
    // check file validty and save positions of texts
    // read until there is something to read
    while (file >> line) {
        
        if (line == "<html>") {
            startHTML = file.tellg();
            cout << line;
            enterHTML = true;
        }

        if (line == "<head>") {
            startHEAD = file.tellg();
            enterHEAD = true;
        }

        if (line == "</head>") {
            endHEAD = file.tellg();
            exitHEAD = true;
        }

        // cannot have end head and not start head
        if (!enterHEAD && exitHEAD) {
            notValidHTML = true;
            errorMessage = "Cannot have end head and not start head";
            break;
        }

        // cannot have end head before start head
        if ((enterHEAD && exitHEAD) && (endHEAD < startHEAD)) {
            notValidHTML = true;
            errorMessage = "cannot have end head before start head";
            break;
        }

        if (line == "<body>") {
            startBODY = file.tellg();
            enterBODY = true;
        }

        // cannot have end head after start body
        if ((enterBODY && exitHEAD) && (endHEAD > startBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have end head after start body";
            break;
        }

        // cannot have head or body without html
        if ((!enterHTML && enterHEAD) || (!enterHTML && enterBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have head or body without html";
            break;
        }

        // cannot have head or body before html
        if ((enterHTML && enterHEAD && enterBODY) && (startHTML > startHEAD || startHTML > startBODY)) {
            notValidHTML = true;
            cout << startHTML << "\n" << startHEAD << "\n" << startBODY << "\n";
            errorMessage = "cannot have head or body before html";
            break;
        }

        // HANDLE OF B!
        if (line == "<b>") {
            startB = file.tellg();
            enterB = true;
        }

        // cannot have b without body
        if (enterB && !enterBODY) {
            notValidHTML = true;
            errorMessage = "cannot have b without body";
            break;
        }

        // cannot have b before body
        if ((enterB && enterBODY) && (startB < startBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have b before body";
            break;
        }

        // cannot have b after body
        if ((enterB && exitBODY) && (startB > endBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have b after body";
            break;
        }

        if (line == "</b>") {
            endB = file.tellg();
            exitB = true;
        }

        // cannot have end b before start b
        if ((exitB && enterB) && (endB < startB)) {
            notValidHTML = true;
            errorMessage = "cannot have end b before start b";
            break;
        }
        // END B!

        // HANDLE OF I!
        if (line == "<i>") {
            startI = file.tellg();
            enterI = true;
        }

        // cannot have i without body
        if (enterI && !enterBODY) {
            notValidHTML = true;
            errorMessage = "cannot have i without body";
            break;
        }

        // cannot have i before body
        if ((enterI && enterBODY) && (startI < startBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have i before body";
            break;
        }

        // cannot have i after body
        if ((enterI && exitBODY) && (startI > endBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have i after body";
            break;
        }

        if (line == "</i>") {
            endI = file.tellg();
            exitI = true;
        }

        // cannot have end i before start i
        if ((exitI && enterI) && (endI < startI)) {
            notValidHTML = true;
            errorMessage = "cannot have end i before start i";
            break;
        }
        // END I!

        // HANDLE OF A!
        if (line == "<a>") {
            startA = file.tellg();
            enterA = true;
        }

        // cannot have a without body
        if (enterA && !enterBODY) {
            notValidHTML = true;
            errorMessage = "cannot have a without body";
            break;
        }

        // cannot have a before body
        if ((enterA && enterBODY) && (startA < startBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have a before body";
            break;
        }

        // cannot have a after body
        if ((enterA && exitBODY) && (startA > endBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have a after body";
            break;
        }

        if (line == "</a>") {
            endI = file.tellg();
            exitA = true;
        }

        // cannot have end a before start a
        if ((endA && startA) && (endA < startA)) {
            notValidHTML = true;
            errorMessage = "cannot have end a before start a";
            break;
        }
        // END A!

        // cannot have b in the middle of i or viceversa
        if ((enterB && exitB) && (enterI && exitI) && ((startB < startI && endB < endI) || (startI < startB && endI < endB))) {
            notValidHTML = true;
            //cout << startB << endB << startI << endI << "\n";
            errorMessage = "cannot have b in the middle of i or viceversa";
            break;
        }

        // cannot have i inside b or viceversa
        if ((enterB && exitB) && (enterI && exitI) && ((startB < startI && endI < endB) || (startI < startB && endB < endI))) {
            notValidHTML = true;
            errorMessage = "cannot have i inside b or viceversa";
            break;
        }

        // cannot have b in the middle of a or viceversa
        if ((enterB && exitB) && (enterA && exitA) && ((startB < startA && endB < endA) || (startA < startB && endA < endB))) {
            notValidHTML = true;
            errorMessage = "cannot have b in the middle of a or viceversa";
            break;
        }

        // cannot have a inside b or viceversa
        if ((enterB && exitB) && (enterA && exitA) && ((startB < startA && endA < endB) || (startA < startB && endB < endA))) {
            notValidHTML = true;
            errorMessage = "cannot have a inside b or viceversa";
            break;
        }

        // cannot have a in the middle of i or viceversa
        if ((enterA && exitA) && (enterI && exitI) && ((startA < startI && endA < endI) || (startI < startA && endI < endA))) {
            notValidHTML = true;
            errorMessage = "cannot have a in the middle of i or viceversa";
            break;
        }

        // cannot have i inside a or viceversa
        if ((enterA && exitA) && (enterI && exitI) && ((startA < startI && endI < endA) || (startI < startA && endA < endI))) {
            notValidHTML = true;
            errorMessage = "cannot have i inside a or viceversa";
            break;
        }

        if (line == "</body>") {
            endBODY = file.tellg();
            exitBODY = true;
        }

        // cannot have end body without start body
        if (!enterBODY && exitBODY) {
            notValidHTML = true;
            errorMessage = "cannot have end body without start body";
            break;
        }

        // cannot have end body before start body
        if ((enterBODY && exitBODY) && (endBODY < startBODY)) {
            notValidHTML = true;
            errorMessage = "cannot have end body before start body";
            break;
        }

        if (line == "</html>") {
            endHTML = file.tellg();
            exitHTML = true;
        }

        // cannot have end html without end body
        if (!exitBODY && exitHTML) {
            notValidHTML = true;
            errorMessage = "cannot have end html without end body";
            break;
        }

        // cannot have end html before end body
        if ((exitBODY && exitHTML) && (endBODY > endHTML)) {
            notValidHTML = true;
            errorMessage = "cannot have end html before end body";
            break;
        }
        
        // If all rules are enforced
        if (enterB && exitB) {
            vector<streampos> bText;
            bText.push_back(startB);
            bText.push_back(endB);
            textIndexes["b"].push_back(bText);
            enterB = false;
            exitB = false;
        }
        
        if (enterI && exitI) {
            vector<streampos> iText;
            iText.push_back(startI);
            iText.push_back(endI);
            textIndexes["i"].push_back(iText);
            enterI = false;
            exitI = false;
        }

        if (enterA && exitA) {
            vector<streampos> aText;
            aText.push_back(startA);
            aText.push_back(endA);
            textIndexes["a"].push_back(aText);
            enterA = false;
            exitA = false;
        }
    }
    // close the file
    file.close();

    if (notValidHTML) {
        cout << "Not a valid HTML file!" << "\n";
        cout << errorMessage << "\n";
        return emptyMap;
    }

    map<string, vector<string>> result = fillMap(textIndexes, fileName);
    return result;
}