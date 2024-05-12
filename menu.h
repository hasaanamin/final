#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>
using namespace sf;
class menu {
public:

	Text playerChange;
	Text playerScore;
	Font font;
	Texture menu0;
	Sprite menu1;
	void initializeText(sf::Text& text, sf::Font& font, const std::string& initialText, int posX, int posY) {
		if (!font.loadFromFile("fonts/arial.ttf")) { // Replace with your font file path
			std::cout << "Failed to load font!" << std::endl;
			
		}
		text.setFont(font);
		text.setString(initialText);
		text.setCharacterSize(24); // Set size to 24 pixels
		text.setFillColor(sf::Color::Black); // White color
		text.setPosition(posX, posY); // Position it at the specified coordinates
	}
	menu() {
		menu0.loadFromFile("Background/menu.jpg");//load the file for the map
		menu1.setTexture(menu0);
		menu1.setPosition(0, 0);
		initializeText(playerChange, font, "Press Down to change player\n, Press Enter to change name after typing it", 950, 0);

	}
	void handleTextInput(sf::Event& event, std::string& inputString) {
		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode < 128) { // Handle ASCII characters
				char enteredChar = static_cast<char>(event.text.unicode);
				if (enteredChar == 8 && !inputString.empty()) { // Handle backspace
					inputString.pop_back();
				}
				else if (enteredChar >= 32 && enteredChar <= 126) { // Handle printable characters
					inputString += enteredChar;
				}
			}
		}
	}
};