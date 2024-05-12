#pragma once
#include"SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <ctime>
#include"levels.h"

using namespace std;
using namespace sf;

class Zombies{
public:
	int hitpoints;
	int direction;
	float speed;
    int damage;
    int XPos;
    bool score = false;
    int Ypos;
    Sprite zombSprite;
    Texture zombText;
    int frames;
    int currentFrame = 0;
    Zombies* backup[4];

    int backupCount = 0;
    
public:
   
    int getHitpoints() const;
    int getDirection() const;
    int getSpeed() const;
    int getXpos();
    int getYpos();
    // Setters
    void setXpos(int x);
    void setYpos(int y);
    void setHitpoints(int hp);
    void setDirection(int dir);
    void setSpeed(int spd);
    void move();
    virtual void move(Clock t1) {};
    void setText(Texture t1) {
        zombSprite.setTexture(t1);
    }
    void setTextRect(IntRect r1) {
        zombSprite.setTextureRect(r1);
    }
    Sprite getSprite() {
        return zombSprite;
    }
    virtual void backupSummon(Clock t1, RenderWindow& window) {};


};