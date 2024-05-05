# include <cstdlib>
# include <iostream>
# include "comparable.h"
# include "reverseOrder.h"
# include <algorithm>

using namespace std;


ReverseOrder::~ReverseOrder () 
{
    cout << "Destructing ReverseOrder" << "\n";
}


int ReverseOrder::compare (const string& lhs, const string& rhs) 
{   
    // opposite results as comparing in ascending order.
    if (lhs.compare(rhs) == 1) {
        return -1;
    }
    else if (lhs.compare(rhs) == -1) {
        return 1;
    }
    else {
        return 0;
    }
}