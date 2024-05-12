#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
class scoreboard {
	public:
		Texture scoreBoard;
		
		Sprite scoreboard1;
		
		scoreboard() {
			scoreBoard.loadFromFile("Background/scoreboard.png");
			scoreboard1.setTexture(scoreBoard);
		}



};