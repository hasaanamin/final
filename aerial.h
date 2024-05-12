#pragma once
#include"zombie.h"
class aerial :public Zombies {
public:
	aerial() {
		zombText.loadFromFile("Spritesheets/bucHeadZombEat.png");
		zombSprite.setTexture(zombText);
		frames = 11;
		speed = 1;
		hitpoints = 10;
		for (int i = 0; i < 4; i++)
			backup[i] = nullptr;
		direction = 1;
	}
	void move(Clock t1) {
		XPos -= speed;
	}

};