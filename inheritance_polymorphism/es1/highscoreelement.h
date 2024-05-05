
# ifndef HIGHSCOREELEMENT
# define HIGHSCOREELEMENT

using namespace std;

class HighScoreElement: public Comparable 
{
    public:
        // constructor.
        HighScoreElement (string name, int score);
        ~HighScoreElement ();
        int compare (Comparable& other);
        void toString();
        string getName();
    private:
        string name;
        int score;
};

# endif
