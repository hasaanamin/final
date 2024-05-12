#include"basic.h"
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
basic::basic(int hit, int speed, float dir, int x, int y) {
	setDirection(dir);
	setHitpoints(hit);
	setSpeed(speed);
	setXpos(x);
	setYpos(y);
	zombSprite.setTexture(zombText);
}
Sprite basic::drawBasic(RenderWindow& window, int frames) {
	
	if (!zombText.loadFromFile("Spritesheets/nZombWalk.png")) {

	}
	
	
	frames = (frames + 1) % 22;
	//IntRect zombRect(0,0,166,144);
	zombSprite.setTextureRect(IntRect(frames * 166, 0, 166, 144));
	zombSprite.setPosition(getXpos(), getYpos());
	XPos -= speed;
	window.draw(zombSprite);
	return zombSprite;



}
