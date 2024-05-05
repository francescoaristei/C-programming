// Tower of Hanoi

// https://www.lancaster.ac.uk/stor-i-student-sites/lidia-andre/2021/03/30/tower-hanoi/#:~:text=The%20Tower%20of%20Hanoi%20problem,one%20disc%20at%20a%20time

# include <cstdlib>
# include <iostream>

using namespace std;


void printMove (int disks, int start, int end) {
    cout << "Move disk " << disks << " from " << start << " to " << end << "\n";
}

// If you take the case with disks = 3, start = 1, end = 3 you have to:
// 1. move the top 2 disks from the rod 1 to rod 2. To do so:
// 1.1. move disk 1 from rod 1 to rod 3.
// 1.2. move disk 2 from rod 1 to rod 2.
// 1.3 move disk 1 from rod 3 to rod 2.
// 2. move disk 3 from rod 1 to rod 3.
// 3. move disk 1 and 2 from rod 2 to rod 3. To do so:
// 3.1. move disk 1 from rod 2 to rod 1.
// 3.2. move disk 2 from rod 2 to rod 3.
// 3.3. move disk 1 from rod 1 to rod 3.
// DONE: now the three disks have been moved from rod 1 to rod 3 in the same cone shape as in the beginning (disk 1 on top, then 2 and 3 on the base).
// If you follow the algorithm below with the case descrived above, you see that it prints exactly the moves from 1. to 3. written above.
// The idea is to take the n-1 disks and move them from the start to the auxiliary rod (other). Then move the largest disk from the start to the end.
// Finally, move the n-1 disks from the auxiliary rod to the end rod. This procedure has a recursive nature: the problem with n disks can be solved
// applying the procedure to the problem with n - 1 disks, which can be solved by applying the procedure to the problem with n - 2 disks etc...
// For example, in the case of n = 4, start = 1 and end = 3 the problem is solved by applying the procedure for the 3 disks on the top and moving them
// from rod 1 to rod 2. Then the disk 4 is moved to the end rod = 3. Then the algorithm continues moving the 3 disks on the rod = 2 to the end rod = 3.
// Moving the 3 disks from the start rod = 1 to the auxiliary rod = 2 requires solving the problem for n = 3. And we do it with the procedure we have
// seen above. Same goes to solve the problem of moving the 3 disks from the auxiliary rod to the end rod. This is the recursive nature of the problem.

// NOTE: an important trick to understand is the other rod. The other rod is computed to be always the rod that is not the start nor the end rod.

void tower (int disks, int start, int end) {
    if (disks == 1) {
        printMove(disks, start, end);
        return;
    }
    int other = 6 - (start + end);
    tower(disks - 1, start, other);
    printMove(disks, start, end);
    tower(disks - 1, other, end);
}

int main () {
    int start;
    int end;
    int nDisks;

    cout << "Set start rod: ";
    cin >> start;
    cout << "Set end rod: ";
    cin >> end;
    cout << "Set n. of disks: ";
    cin >> nDisks;

    tower(nDisks, start, end);
}