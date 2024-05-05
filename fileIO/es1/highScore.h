/*
Reimplement the text file version of the high-score program that inserts into the correct file position,
but do it using a binary file format instead of a text file format. How can you tell if your program is
working? Create a program that displays the file as a text file.
*/

# ifndef HIGHSCORE
# define HIGHSCORE

# include <iostream>
# include <fstream>

using namespace std;


class HighScore {
    public:
        int addScore (fstream& file);
        int printContent (fstream& fileName);
};

# endif
