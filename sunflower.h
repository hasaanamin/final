#pragma once
#include"plant.h"
class sunflower :public Plant {
public:
	sunflower(int x,int y, Plant* plants[], int plantCount) {
		hitpoints = 10;
		setPosX(x);
		setPosY(y);
		
		
	}
};