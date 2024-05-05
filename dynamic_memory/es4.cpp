// list of friends

# include <cstdlib>
# include <iostream>

using namespace std;

int* growFriends (int **head, int nUser, int size) {
    // create new array of friends with increased size
    int *copyFriends = new int [2 * size];
    for (int i = 0; i < size; i++) {
        copyFriends[i] = head[nUser][i];
    }
    delete [] head[nUser];
    return copyFriends;
}

void displayUsers(int **head, int users, int friends[]) {
    for (int i = 0; i < users; i++) {
        cout << "----------" << "\n";
        cout << "User " << i << ": " << "\n";
        for (int j = 0; j < friends[i]; j++) {
            cout << "- friend " << j << ", talked: " << head[i][j] << " times" << "\n";
        }
    }
}

int main () {
    // head of the two dim array
    int **head = NULL;

    // number of users decided upfront
    int users;

    // pointer to array containing number of friends for each user
    int *sizes = NULL;

    // counter to keep track if the array of friends associated to a user needs to be increased
    int *counters = NULL;

    cout << "Set the number of users: ";
    cin >> users;

    // each user point to an array of friends
    head = new int* [users];

    bool keepTrack = true;

    // initialize with admin
    int nUser = -1;

    // initialize the number of friends for each user to 2
    sizes = new int[users];
    for (int i = 0; i < users; i++) {
        sizes[i] = 2;
    }

    // initialize the counters to keep track of the friends for each user
    counters = new int[users];
    for (int i = 0; i < users; i++) {
        counters[i] = 0;
    }

    // initialize the number of friends for each user
    for (int i = 0; i < users; i++) {
        head[i] = new int[sizes[i]];
    }

    while (keepTrack) {
        if (nUser == -1) {
            int adminChoice;
            cout << "Admin, 1 to let users play, 0 to terminate the game: ";
            cin >> adminChoice;
            if (adminChoice == 0) {
                cout << "Game terminated!";
                break;
            }
        }
        cout << "Which user are you (number)? ";
        cin >> nUser;
        int choice;
        int nFriend;
        cout << "1. Click 1 to add a new friend. " << "\n";
        cout << "2. Click 2 to initialize/update the number of days since you last talked to a friend." << "\n";
        cout << "3. Click 3 to exit the game." << "\n";
        cin >> choice;

        if (choice == 1) {
            if (sizes[nUser] >= counters[nUser]) {
                // first time the user speaks to this new friend
                head[nUser][counters[nUser]] = 1;
                counters[nUser] += 1;
            }
            else {
                head[nUser] = growFriends(head, nUser, sizes[nUser]);
                head[nUser][counters[nUser]] = 1;
            }
            cout << "Friend added!" << "\n";
        }
        else if (choice == 2) {
            int friendIndex;
            cout << "Choose the friend to update (between 0 and " << counters[nUser] -1 << "): ";
            cin >> friendIndex;
            int update;
            cout << "Set the number of times you have spoken with the friend: " << friendIndex << ": ";
            cin >> update;
            head[nUser][friendIndex] = update;
        }
        else {
            nUser = -1;
        }

        displayUsers(head, users, counters);
    }

    // delete
    for (int i = 0; i < users; i++) {
        delete[] head[i];
    }

    delete head;
}