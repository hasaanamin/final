#pragma once
#include"plantFactory.h"
#include"zombie.h"
#include"levels.h"
#include"SFML/Graphics.hpp"
#include<iostream>
using namespace std;
class Plant:public PlantFactory{
public:
	int hitpoints;
	int buyVal;
	int posX;
	int posY;
    Texture plantText;
    Sprite sprite;
    bool shooter = false;
    int getHitPoints() ;
    int getBuyVal() const;
    int getPosX() const;
    int getPosY() const;
    bool isPlantAlive();
    // Setter prototypes
    void setHitPoints(int hp);
    void setBuyVal(int value);
    void setPosX(int x);
    void setPosY(int y);
    bool checkCollision(Zombies* b1[], int i) {
        int plantRight = posX  ;   // Right edge of the plant
        int plantBottom = posY;  // Bottom edge of the plant
        int zombieRight = b1[i]->XPos + 166;   // Right edge of the zombie
        int zombieBottom = b1[i]->Ypos + 144;  // Bottom edge of the zombie

        // Check if any of the sides from one rectangle is outside the other
        if (b1[i]->XPos < plantRight && zombieRight > posX && b1[i]->Ypos < plantBottom && zombieBottom > posY&&b1[i]->hitpoints>0) {
            hitpoints -= b1[i]->damage;
            cout << "Collision detected!" << endl;
            return true;
        }
        else {
            return false;
        }
    }
    virtual bool checkBullet(Zombies* b1) { return false; };
    virtual void fire(RenderWindow& window) {};
    virtual void repeatFire(RenderWindow& window) {};
    virtual void allahuakbar(Zombies* osama[], int i, int x) {};
    virtual bool checkSnowBullet(Zombies* b1) { return false; };
    virtual bool checkRepeatBullet(Zombies* b1) { return false; };
    virtual void move() {};
    
};