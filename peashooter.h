#pragma once
#include"SFML/Graphics.hpp"
#include<ctime>
#include"shooter.h"
using namespace sf;
using namespace std;

class Peashooter :public shooter {


public:
	Peashooter(int dam, int pel, int intrvl, int hit, int buy, int x, int y) {
		setBuyVal(buy);
		setDamage(dam);
		setHitPoints(hit);
		setInterval(intrvl);
		setPellet(pel);
		setPosX(x);
		setPosY(y);
		bulletX = x;
		bulletY = y;

	}
	Peashooter() {
		hitpoints = 10;
		pellet = 1;
		damage = 4;
		
	}
	Peashooter(int x, int y, Plant* plants[], int plantCount) {
		setPosX(x);
		setPosY(y);
		setHitPoints(10);
		setDamage(4);
		
		//plants[plantCount]->sprite.setOrigin(20,35);
		bulletX = x+10;
		bulletY = y + 10;
	



	}
	void drawPea(RenderWindow& window,float time);
};