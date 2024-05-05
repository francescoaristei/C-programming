
# ifndef REVERSEORDER
# define REVERSEORDER

# include "comparable.h"
# include <iostream>
# include <cstdlib>
# include <string>

using namespace std;

class ReverseOrder: public Comparable 
{
    public:
        ~ReverseOrder ();
        int compare (const string& lhs, const string& rhs);
};

# endif