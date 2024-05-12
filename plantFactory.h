#pragma once
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;


struct Card {
	Sprite sprite;
	int cost;
	int Xpos;
	int Ypos;
	bool isSelected;
	Texture cardText;
};


struct PlantFactory {

	Texture plantText;
	Sprite sprite;

	

};