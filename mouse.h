#pragma once
#include"SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include"peashooter.h"
using namespace std;
using namespace sf;
class mouse {
	int selectX;
	int selectY;
	int placeX;
	int placeY;
public:
	mouse() {
		selectX = 0;
		selectY = 0;
		placeX = 0;
		placeY = 0;
	}
	mouse(int x, int y) {
		selectX = x;
		selectY = y;
		placeX = 0;
		placeY = 0;
	}
	int cardChoice(RenderWindow& window, Event event) {
		bool select = false;
		int card = 0;
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				int selectX = event.mouseButton.x;
				int selectY = event.mouseButton.y;
			}
		}
		for (int i = 70; i < 1400; i += 95) {
			if (selectX > i && selectX < i + 95 && selectY > 600) {
				select = true;
				card = i;
				break;
			}
		}
		if (select == true) {
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					int placeX = event.mouseButton.x;
					int placeY = event.mouseButton.y;
				}
			}
		

					//implement mouse click
					switch (card) {
					case 0:
						break;
					case 1:
						Peashooter p2(10, 1, 3, 19, 11, placeX, placeY);
						p2.drawPea(window);
						select = false;
						break;
					case 2:
						//draw repeater
						break;
					case 3:
						//draw snowpea
						break;
					}
				}
				return card;
			}

		




};