#include"plant.h"
class lawnMower {
public:
	bool unused = true;
	int posX;
	int posY;
    Sprite sprite;
    Texture text;
    bool checkCollision(Zombies* b1[], int i) {
        int plantRight = posX;   // Right edge of the plant
        int plantBottom = posY+50;  // Bottom edge of the plant
        int zombieRight = b1[i]->XPos + 166;   // Right edge of the zombie
        int zombieBottom = b1[i]->Ypos + 144;  // Bottom edge of the zombie

        // Check if any of the sides from one rectangle is outside the other
        if (b1[i]->XPos < plantRight && zombieRight > posX && b1[i]->Ypos < plantBottom && zombieBottom > posY && b1[i]->hitpoints > 0) {
            b1[i]->hitpoints = 0;
            cout << "Collision detected!" << endl;
            return true;
        }
        else {
            return false;
        }
    }
};