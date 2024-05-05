# ifndef XMLPARSER
# define XMLPARSER

# include <iostream>


using namespace std;


class XmlParser {
    public:
        bool validateXML (string fileName);
        void nodeStart (string node, int spaces);
        void attributeRead (string attribute, int spaces);
        void nodeTextRead (string text, int spaces);
        void nodeEnd (string nodeEnd, int spaces);
        void readXML (string fileName);
};

# endif