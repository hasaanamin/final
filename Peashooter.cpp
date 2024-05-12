#include "peashooter.h"
#include"SFML/Graphics.hpp"
#include<ctime>
#include"plant.h"
using namespace sf;
using namespace std;

// Getters


void Peashooter::drawPea(RenderWindow& window, float time) {
	sf::Clock animationClock; // Clock to time the animation frame changes
	int currentFrame = 0;
	const int totalFrames = 13; // Number of frames in your animation row

		Texture peaText;
		if (peaText.loadFromFile("Spritesheets/peashooter.png")); {

		}
		IntRect spriteRect(0, 0, 71, 71);
		Sprite peaSprite;
		peaSprite.setTexture(peaText);
		peaSprite.setTextureRect(spriteRect);
		peaSprite.setPosition(posX, posY);
		
		window.draw(peaSprite);
		
		//shooter::fire(window,time);
		
}
