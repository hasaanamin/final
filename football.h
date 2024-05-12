#pragma once
#include"zombie.h"
class football :public Zombies {
	Clock t2;
public:
	football() {
		zombText.loadFromFile("Spritesheets/bucHeadZombWalk.png");
		zombSprite.setTexture(zombText);
		for (int i = 0; i < 4; i++)
			backup[i] = nullptr;
		speed = 2;
		hitpoints = 20;;
		frames = 15;


	}
	void move(Clock t1) {
		srand(0);
		this->XPos = XPos - speed;
		int x = t2.getElapsedTime().asSeconds();
		if(speed>0)
		if (((x % 8)) == 0)
			speed = speed * (-1);
		if(speed<0)
			if (((x % 5)) == 0)
				speed = speed * (-1);
		if (XPos > 1300)
			speed = 2;
		



	}
};