# include <iostream>
# include "xmlParser.h"

using namespace std;

int main (int argc, char* argv[]) {
    XmlParser *parser = new XmlParser();
    bool result = parser -> validateXML(argv[1]);

    if (result) {
        parser -> readXML (argv[1]);
    }
}