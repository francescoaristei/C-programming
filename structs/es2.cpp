# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

struct SpaceShip {
    int xcoord;
    int ycoord;
};

SpaceShip updateCoords (SpaceShip spaceShip) {
    spaceShip.xcoord = 0 + ( rand() % ( 1024 - 0 + 1 ) );
    spaceShip.ycoord = 0 + ( rand() % ( 768 - 0 + 1 ) );
    return spaceShip;
}

int main() {
    srand(time(NULL));
    SpaceShip spaceShip;
    spaceShip.xcoord = 0 + ( rand() % ( 1024 - 0 + 1 ) );
    spaceShip.ycoord = 0 + ( rand() % ( 768 - 0 + 1 ) );
    while (spaceShip.xcoord < 1024 && spaceShip.ycoord < 768) {
        spaceShip = updateCoords(spaceShip);
        cout << "The x coord is: " << spaceShip.xcoord << "\n";
        cout << "The y coord is: " << spaceShip.ycoord << "\n";
    }

    cout << "The coordinates have gone ouside the screen!" << "\n";

}
