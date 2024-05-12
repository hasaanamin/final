#include"zombie.h"
#include <SFML/Graphics.hpp>
#include <ctime>
int Zombies::getHitpoints() const {
    return hitpoints;
}

int Zombies::getDirection() const {
    return direction;
}

int Zombies::getSpeed() const {
    return speed;
}

// Setters implementation
void Zombies::setHitpoints(int hp) {
    hitpoints = hp;
}

void Zombies::setDirection(int dir) {
    direction = dir;
}

void Zombies::setSpeed(int spd) {
    speed = spd;
}
int Zombies::getXpos() {
    return XPos;
}
int Zombies::getYpos() {
    return Ypos;
}
void Zombies::setXpos(int x) {
    XPos = x;
}
void Zombies::setYpos(int y) {
    Ypos = y;
}
void Zombies::move() {
    XPos -= 5;



}
