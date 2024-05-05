
# ifndef COMPARABLE
# define COMPARABLE

# include <iostream>

using namespace std;

class Comparable 
{
    public:
        // pure virtual
        virtual int compare (const string& lhs, const string& rhs) = 0;
        virtual ~Comparable ()  { cout << "Destructing Comparable " << "\n";};
};
# endif
