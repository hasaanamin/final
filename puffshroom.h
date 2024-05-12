#pragma once
#include"plant.h"
class puffshroom :public Plant {
public:
	puffshroom(int x,int y) {
		setPosX(x);
		setPosY(y);
		
		setHitPoints(10);
			
	}
	void allahuakbar(Zombies* osama[], int i,int x) {
		int plantRight = posX + 100;   // Right edge of the plant
		int plantBottom = posY + 71;  // Bottom edge of the plant
		int plantLeft = posX +50;  // Extend left boundary by buffer
		int plantTop = posY - 50;
		int zombieRight = osama[i]->XPos + 130;   // Right edge of the zombie
		int zombieBottom = osama[i]->Ypos + 144;  // Bottom edge of the zombie
		//cout << hitpoints << endl;
	
			for (i = 0; i < x; i++) {
				if (osama[i]->XPos < plantRight && osama[i]->XPos + 144 > plantLeft &&
					osama[i]->Ypos < plantBottom && osama[i]->Ypos + 166 > plantTop &&
					osama[i]->hitpoints > 0) {
					osama[i]->hitpoints -= 1;
					cout << "allahuakbar\n";
				}
			}
			//cout << hitpoints << endl;
			

		}
	




};