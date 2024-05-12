#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include"zombie.h"
using namespace sf;
class basic :public Zombies {
public:
		basic(int hit, int speed, float dir, int x, int y);
		Sprite drawBasic(RenderWindow& window,int frames);
		void move(Clock t1) {
			XPos -= speed;
		}
		basic(int x, int y) {
			zombText.loadFromFile("Spritesheets/nZombWalk.png");
			zombSprite.setTexture(zombText);
			XPos = x;
			Ypos = y;
			speed = 4;
			hitpoints = 10;
		}
		basic() {
			zombText.loadFromFile("Spritesheets/nZombWalk.png");
			zombSprite.setTexture(zombText);
			frames = 22;
			speed = 1;
			for (int i = 0; i < 4; i++)
				backup[i] = nullptr;
			hitpoints = 10;
		}
	};