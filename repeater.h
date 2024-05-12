#include"shooter.h"
#include"SFML/Graphics.hpp"
using namespace sf;
class repeater :public shooter {
public:
	repeater(int x, int y, Plant* plants[], int plantCount) {
		bulletX = x;
		bulletY = y;
		posX = x;
		posY = y;
		hitpoints = 10;
		



	}
	void repeatFire(RenderWindow& window){
		
			fire(window);
		

	}
	bool checkRepeatBullet(Zombies* b1) {

		int bulletRight = bulletX + 28;   // Right edge of the bullet
		int bulletBottom = bulletY + 28;  // Bottom edge of the bullet
		int zombieRight = b1->XPos + 166;   // Right edge of the zombie
		int zombieBottom = b1->Ypos + 144;  // Bottom edge of the zombie

		// Check if any of the sides from one rectangle is outside the other
		if (b1->XPos + 50 < bulletX && b1->XPos + 144 > bulletX && b1->Ypos < bulletBottom && zombieBottom > posY && b1->hitpoints > 0) {
			cout << "Collision detected!" << endl;
			cout << "hitpoints left :" << b1->hitpoints << endl;

			b1->hitpoints = b1->hitpoints - 10;
			cout << "hitpoints left :" << b1->hitpoints << endl;

			bulletX = posX;
			bulletY = posY;
			return true;

		}
		else {
			return false;
		}

	}



};