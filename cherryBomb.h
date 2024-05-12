#pragma once
#include"SFML/Graphics.hpp"
#include"plant.h"
using namespace sf;
class cherrybomb :public Plant {
public:
	cherrybomb(int x, int y, Plant* plants[], int plantCount) {
		setPosX(x);
		setPosY(y);
		
		hitpoints = 600;
	}
	void allahuakbar(Zombies* osama[], int i, int x) {
		int plantRight = posX + 100;   // Right edge of the plant
		int plantBottom = posY + 71 + 100;  // Bottom edge of the plant
		int plantLeft = posX + 100;  // Extend left boundary by buffer
		int plantTop = posY - 100;
		int zombieRight = osama[i]->XPos + 166;   // Right edge of the zombie
		int zombieBottom = osama[i]->Ypos + 144;  // Bottom edge of the zombie
		cout << hitpoints << endl;
		if (checkCollision(osama, i)) {
			cout << "allahuakbar\n";
			//cout << hitpoints << endl;
			for (i = 0; i < x; i++) {
				if (osama[i]->XPos < plantRight && osama[i]->XPos + 144 > plantLeft &&
					osama[i]->Ypos < plantBottom && osama[i]->Ypos + 166 > plantTop &&
					osama[i]->hitpoints > 0)
					osama[i]->hitpoints = 0;
				cout << "allahuakbar\n";
			}
			
			hitpoints = 0;
			
		}
	}



};