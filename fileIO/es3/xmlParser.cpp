# include <fstream>
# include <iostream>
# include <vector>
# include "xmlParser.h"

using namespace std;



bool XmlParser::validateXML (string fileName) {
    fstream file (fileName, ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Error opening file, exiting!" << "\n";
        return false;
    }

    // stack to hold the start node, whenever the corresponding end node is found a pop is done.
    // if the read ending node does not match with the top of the stack the file is not a valid XML
    vector<string> stack;
    string line;
    while (file >> line) {
        if (line[0] == '<' && line[line.length() - 1] == '>' && line[1] != '/') {
            if (line.find("attribute") != string::npos) {
                // extract just the name of the node
                stack.push_back(line.substr(1, line.length() - 1 - (line.length() - line.find("attribute"))));
            }
            else {
                stack.push_back(line.substr(1, line.length() - 1 - 1));
            }
        }

        if (line[0] == '<' && line[line.length() -1] == '>' && line[1] == '/') {
            // end node, match it with the top of the stack
            if (line.substr(2, line.length() - 2 - 1) == stack.back()) {
                stack.pop_back();
            }
            else {
                cout << "The XML files has an invalid format, exiting! " << "\n";
                return false;
            }
        }


    }

    if (stack.empty()) {
        return true;
    }

    return false;
}



void XmlParser::nodeStart (string node, int spaces) {
    for (int i = 0; i < spaces; i++) {
        cout << " ";
    }
    cout << node << "\n";
}


void XmlParser::attributeRead (string attribute, int spaces) {
    for (int i = 0; i < spaces; i++) {
        cout << " ";
    }
    cout << attribute << "\n";
}

void XmlParser::nodeTextRead (string text, int spaces) {
    for (int i = 0; i < spaces; i++) {
        cout << " ";
    }
    cout << text << "\n";
}


void XmlParser::nodeEnd (string endNode, int spaces) {
    for (int i = 0; i < spaces; i++) {
        cout << " ";
    }
    cout << endNode << "\n";
}


void XmlParser::readXML (string fileName) {
    fstream file (fileName, ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Error reading the file, exiting!" << "\n";
        return;
    }

    int spaceCounter = 0;
    string line;
    while (file >> line) {
        if (line[0] == '<' && line[1] != '/' && line[line.length() - 1] == '>') {
            if (line.find("attribute") != string::npos) {
                string node = line.substr(1, line.length() - 2 - (line.length() - line.find("attribute")));
                nodeStart(node, spaceCounter);
                string attribute = line.substr(line.find("="), line.length() - 2 - line.find("="));
                attributeRead(attribute, spaceCounter);
                spaceCounter += 1;
            }
            else {
                string node = line.substr(1, line.length() - 1 - 1);
                nodeStart(node, spaceCounter);
                spaceCounter += 1;
            }
        }

        else if (line[0] == '<' && line[1] == '/' && line[line.length() - 1] == '>') {
            // NOTE: important that is here and not after nodeEnd()
            spaceCounter -= 1;
            string nodeE = line.substr(2, line.length() - 2 - 1);
            nodeEnd(nodeE, spaceCounter);
        }
        else {
            nodeTextRead(line, spaceCounter);
        }
    }
}





