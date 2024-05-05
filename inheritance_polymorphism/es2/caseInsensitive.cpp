# include <cstdlib>
# include <iostream>
# include "comparable.h"
# include "caseinsensitive.h"
# include <algorithm>

using namespace std;


CaseInsensitive::~CaseInsensitive () 
{
    cout << "Destructing CaseInsensitive" << "\n";
}

int CaseInsensitive::compare (const string& lhs, const string& rhs) 
{   
    string lhsToLower;
    string rhsToLower;

    transform(lhs.begin(), lhs.end(), lhsToLower.begin(), ::tolower);
    transform(rhs.begin(), rhs.end(), rhsToLower.begin(), ::tolower);
    
    // return -1 if lhs comes before rhs, 0 if equals and 1 if comes after (comes in alphabetical order)
    return lhs.compare(rhs);
}