# include <cstdlib>
# include <iostream>
# include "comparable.h"
# include "highscoreelement.h"

using namespace std;


HighScoreElement::HighScoreElement (string name, int score)
{   
    this -> name = name;
    this -> score = score;
}

HighScoreElement::~HighScoreElement () 
{
    cout << "Destructing HighScoreElement" << "\n";
}

void HighScoreElement::toString ()
{   
    cout << "Element: " << this -> name << ", Score: " << this -> score << "\n";
}

string HighScoreElement::getName () 
{
    return this -> name;
}

int HighScoreElement::compare (Comparable& other) 
{
    int score = static_cast<HighScoreElement&>(other).score;
    if (this -> score > score) {
        return 1;
    }
    else if (this -> score == score) {
        return 0;
    }
    else {
        return -1;
    }
}