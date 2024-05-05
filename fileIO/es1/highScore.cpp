# include "highScore.h"
# include <fstream>
# include <iostream>
# include <vector>

using namespace std;

int HighScore::addScore (fstream& file) 
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
    return 0;
}

int HighScore::printContent (fstream& file) {
    vector<int> scores;
    int score;
    while (file.read(reinterpret_cast<char*> (&score), sizeof(score))) 
    {   
        scores.push_back(score);
    }
    if (file.fail() && !file.eof()) 
    {
        cout << "Bad input or file corrupted, exiting";
        return -1;
    }
    // clear in order to write
    file.clear();

    cout << "The scores in the file are: ";
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i] << " ";
    }
    return 0;
}
