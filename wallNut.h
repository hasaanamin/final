#include"plant.h"
#include"SFML/Graphics.hpp"
class wallnut :public Plant {
public:
	wallnut(int x, int y, Plant* plants[], int plantCount) {
		setPosX(x);
		setPosY(y);
		setHitPoints(600);
		
	}
	void move() {
		posX += 1;
	}


};