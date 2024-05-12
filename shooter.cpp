#include"SFML/Graphics.hpp"
#include<ctime>
#include"shooter.h"
using namespace sf;
using namespace std;
int shooter::getDamage() const {
    return damage;
}

int shooter::getPellet() const {
    return pellet;
}

int shooter::getInterval() const {
    return interval;
}

// Setters
void shooter::setDamage(int dmg) {
    damage = dmg;
}

void shooter::setPellet(int p) {
    pellet = p;
}

void shooter::setInterval(int intvl) {
    interval = intvl;
}
void shooter::fire(RenderWindow& window) {
   // drawPea(window);
   // int time1 = bulletClock.getElapsedTime().asSeconds();
    Sprite bulletSprite;
   

        Texture bulletText;
        bulletText.loadFromFile("Bullets/PeaNormal/pea.png");
            // Handle error here
        
       

        bulletSprite.setTexture(bulletText);

        bulletSprite.setPosition(bulletX, bulletY);
    
   
   
   bulletX += 20;
   if (bulletX > window.getSize().x) {
       bulletX = getPosX(); // Reset to the starting position or where your peashooter is
   }
    window.draw(bulletSprite);
   
  
    
 




}
void shooter::moveBullet(Sprite bulletSprite, float time) {
    
}