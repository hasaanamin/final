#include "plant.h"
#pragma once

// Getters implementation
int Plant::getHitPoints()  {
    return hitpoints;
}

int Plant::getBuyVal() const {
    return buyVal;
}

int Plant::getPosX() const {
    return posX;
}

int Plant::getPosY() const {
    return posY;
}

// Setters implementation
void Plant::setHitPoints(int hp) {
    hitpoints = hp;
}

void Plant::setBuyVal(int value) {
    buyVal = value;
}

void Plant::setPosX(int x) {
    posX = x;
}

void Plant::setPosY(int y) {
    posY = y;
}
bool Plant::isPlantAlive() {
    if (hitpoints <= 0)
        return false;
    else
        return true;
}