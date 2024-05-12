#pragma once
#include"plant.h"
#include"SFML/Graphics.hpp"
#include<ctime>
using namespace sf;
class shooter :public Plant {
protected:
	int damage;
	int pellet;
	int interval;
	int bulletX;
	int bulletY;
	Clock bulletClock;
public:

	int getDamage() const;
	int getPellet() const;
	int getInterval() const;

	// Setters
	void setDamage(int dmg);
	void setPellet(int p);
	void setInterval(int intvl);
   void fire(RenderWindow& window);
	void moveBullet(Sprite bulletSprite, float time);
	shooter operator=(Plant p1) {
		this->bulletX = p1.posX;
		this->bulletY = p1.posY;
		return *this;


	}


	void drawPea(RenderWindow& window) {
		sf::Clock animationClock; // Clock to time the animation frame changes
		int currentFrame = 0;
		const int totalFrames = 13; // Number of frames in your animation row

		Texture peaText;
		if (peaText.loadFromFile("Spritesheets/peashooter.png")) {

		}
		IntRect spriteRect(0, 0, 71, 71);
		Sprite peaSprite;
		peaSprite.setTexture(peaText);
		peaSprite.setTextureRect(spriteRect);
		peaSprite.setPosition(getPosX(), getPosY());

		window.draw(peaSprite);

		//shooter::fire(window,time);

	}
	bool checkBullet(Zombies* b1) {

		int bulletRight = bulletX + 28;   // Right edge of the bullet
		int bulletBottom = bulletY + 28;  // Bottom edge of the bullet
		int zombieRight = b1->XPos + 166;   // Right edge of the zombie
		int zombieBottom = b1->Ypos + 144;  // Bottom edge of the zombie

		// Check if any of the sides from one rectangle is outside the other
		if (b1->XPos+50 < bulletX && b1->XPos+144 > bulletX &&b1->Ypos < bulletBottom && zombieBottom > posY && b1->hitpoints>0) {
			cout << "Collision detected!" << endl;
			cout << "hitpoints left :" << b1->hitpoints << endl;

			b1->hitpoints = b1->hitpoints -  5;
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