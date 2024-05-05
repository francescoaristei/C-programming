# include <cstdlib>
# include <iostream>

using namespace std;

namespace jumpingcpp 
{
    class vectorOfInt {

        public:
            vectorOfInt ();
            vectorOfInt (int size);
            ~vectorOfInt ();
            vectorOfInt& operator= (const vectorOfInt& other);
            vectorOfInt (const vectorOfInt& other);

            int getValue (int index);
            int* setValue (int index, int value);
            int* pushBack (int value);
            int* pushFront (int value);
            void displayVector();

        private:
            int *vector;
            int vSize;
            bool isFull;
            void resize ();
    };
}
