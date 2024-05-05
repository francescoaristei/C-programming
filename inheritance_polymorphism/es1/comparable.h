
# ifndef COMPARABLE
# define COMPARABLE

# include <iostream>

using namespace std;

class Comparable 
{
    public:
        // pure virtual
        virtual int compare (Comparable& other) = 0;
        virtual ~Comparable ()  { cout << "Destructing Comparable " << "\n";};
        virtual void toString() = 0;
};
# endif
