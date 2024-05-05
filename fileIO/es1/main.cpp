# include <cstdlib>
# include <iostream>
# include <fstream>
# include <vector>

using namespace std;

// Works like this or by using the class highScore methods.

int main (int argc, char *argv[]) {

    // write initial score in the file
    fstream file (argv[1], ios::trunc | ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Could not open the file!" << "\n";
        return -1;
    }
    int initialScore;
    cout << "Set an initial score: ";
    cin >> initialScore;
    file.write(reinterpret_cast<char*>(&initialScore), sizeof(initialScore));


    // move to position 0
    file.seekg(0, ios::beg);
    int checkWrite;
    if (!file.read(reinterpret_cast<char*>(&checkWrite), sizeof(checkWrite))) 
    {
        cout << "Error reading from file!" << "\n";
        return -1;
    }
    cout << "First score inserted: " << checkWrite << "\n";


    // move back to the start of the file
    file.seekg(0, ios::beg);
    int loop = 1;
    while (loop) 
    {
        if (!file.is_open())
        {
            cout << "Could not open the file!" << "\n";
            return -1;
        }
        int newHighScore;
        cout << "Enter a new score: ";
        cin >> newHighScore;
        streampos preScorePos = file.tellg();
        int curScore;
        while (file.read(reinterpret_cast<char*> (&curScore), sizeof(curScore))) 
        {
            if (curScore < newHighScore)
            {
                break;
            }
            preScorePos = file.tellg();
        }
        if (file.fail() && !file.eof()) 
        {
            cout << "Bad input or file corrupted, exiting" << "\n";
            file.close();
            return -1;
        }
        // clear in order to write
        file.clear();
        file.seekg(preScorePos);
        vector<int> scores;
        while (file.read(reinterpret_cast<char*> (&curScore), sizeof(curScore))) 
        {
            scores.push_back(curScore);
        }
        if (!file.eof())
        {
            cout << "Bad input or file corrupted, exiting" << "\n";
            file.close();
            return -1;
        }

        file.clear();
        file.seekp(preScorePos);
        file.write(reinterpret_cast<char*>(&newHighScore), sizeof(newHighScore));
        for (vector<int>::iterator itr = scores.begin(), end = scores.end(); itr != end; ++itr) 
        {
            file.write(reinterpret_cast<char*>(&*itr), sizeof(*itr));
        }
            // move back to start of the file before the next loop iteration.
            file.seekg(0, ios::beg);
            cout << "1 to continue, 0 to exit: ";
            cin >> loop;
    }
    vector<int> printScores;
    int score;
    while (file.read(reinterpret_cast<char*> (&score), sizeof(score))) 
    {   
        printScores.push_back(score);
    }
    if (file.fail() && !file.eof()) 
    {
        cout << "Bad input or file corrupted, exiting";
        return -1;
    }
    // clear in order to write
    file.clear();
    // now can close the file
    file.close();

    cout << "The scores in the file are: ";
    for (int i = 0; i < printScores.size(); i++) {
        cout << printScores[i] << " ";
    }
}
