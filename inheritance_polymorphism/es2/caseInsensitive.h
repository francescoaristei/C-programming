
# ifndef CASEINSENSITIVE
# define CASEINSENSITIVE

# include "comparable.h"
# include <iostream>
# include <cstdlib>
# include <string>

using namespace std;

class CaseInsensitive: public Comparable 
{
    public:
        // constructor.
        ~CaseInsensitive ();
        int compare (const string& lhs, const string& rhs);
};

# endif
