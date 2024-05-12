#include <SFML/Graphics.hpp>
#include <ctime>
#include"peashooter.h"
#include"plant.h"
#include"shooter.h"
#include"basic.h"
#include"zombie.h"
#include"plantFactory.h"
#include"repeater.h"
#include"snowPea.h"
#include"wallNut.h"
#include"cherryBomb.h"
#include"sunflower.h"
#include"lawnmower.h"
#include"player.h"
#include"football.h"
#include"dancing.h"
#include"aerial.h"
#include"puffshroom.h"
#include"levels.h"
#include<iostream>
#include<fstream>
#include"menu.h"
#include"zombieFactory.h"
#include"scoreboard.h"
using namespace sf;
using namespace std;
player users[5];
int currentUser = 0;
levels level[6];
int levelCount = 0;
menu menu1;
int x = 0;
struct coordinats
{
	int x;
	int y;
};
int plantCount = 0;
Plant* plants[50];
Peashooter* pea[10];
int peaCount = 0;
Zombies* zombies[20];
repeater* repeat[10];
int repeatCount = 0;
snowPea* snow[10];
int snowCount = 0;
wallnut* wall[10];
int wallCount = 0;
cherrybomb* cherry[10];
int cherryCount = 0;
sunflower* sunflow[10];
int sunCount = 0;
lawnMower lawnmowers[06];
aerial* air[4];
int airCount = 0;
bool gameStart = false;
const int numZombies = 20;
const int minDistance = 50;

scoreboard scoreboard1;
Card cards[7];


void saveScoresToFile(const std::string& filename, player users[], int userCount) {
	ofstream file;
	file.open(filename);
	if (file.is_open()) {
		for (int i = 0; i < 5; ++i) {
			file << users[i].name << " " << users[i].score << "\n";
		}
		file.close();
		std::cout << "Scores saved to " << filename << std::endl;
	}
	else {
		std::cerr << "Unable to open file for writing: " << filename << std::endl;
	}
}

int loadScoresFromFile(const std::string& filename, player users[]) {
	std::ifstream file;
	file.open("scores.txt");
	int userCount = 0;
	if (file.is_open()) {
		while (file >> users[userCount].name >> users[userCount].score) {
			++userCount;
			if (userCount >= 5) break; // Prevent exceeding array bounds
		}
		file.close();
		std::cout << "Scores loaded from " << filename << std::endl;
	}
	else {
		std::cerr << "Unable to open file for reading: " << filename << std::endl;
	}
	return userCount;
}



void plantSet(int i, int x, int y) {

	switch (i)
	{
	case 3:
		if (users[currentUser].sun >= 150) {
			plants[plantCount] = new cherrybomb(x, y, plants, plantCount);
			plants[plantCount]->plantText.loadFromFile("Spritesheets/cherrybomb.png");
			plants[plantCount]->sprite.setTexture(plants[plantCount]->plantText);
			plants[plantCount]->sprite.setTextureRect(IntRect(0, 0, 71, 71));
			plants[plantCount]->sprite.setPosition(x, y);
			cherryCount++;
			users[currentUser].sun -= 150;
			plantCount++;
		}
		else
			cout << "insufficient suns!!!\n";
		break;
	case 1:
		if (users[currentUser].sun >= 100) {
			cout << "hallo\n";
			plants[plantCount] = new Peashooter(x, y, plants, plantCount);
			cout << "hallo0\n";
			plants[plantCount]->plantText.loadFromFile("Spritesheets/peashooter.png");
			plants[plantCount]->sprite.setTexture(plants[plantCount]->plantText);
			plants[plantCount]->sprite.setTextureRect(IntRect(0, 0, 71, 71));
			plants[plantCount]->sprite.setPosition(x, y);
			cout << "hallo0\n";
			//peaCount++;
			users[currentUser].sun -= 100;
			plantCount++;
			cout << "halo1\n";
		}
		else
			cout << "insuffucient suns!!!\n";
		break;
	case 4:
		if (users[currentUser].sun >= 200) {
			plants[plantCount] = new repeater(x, y, plants, plantCount);
			//repeatCount++;
			plants[plantCount]->plantText.loadFromFile("Spritesheets/repeater.png");
			plants[plantCount]->sprite.setTexture(plants[plantCount]->plantText);
			plants[plantCount]->sprite.setTextureRect(IntRect(0, 0, 71, 71));
			plants[plantCount]->sprite.setPosition(x, y);
			users[currentUser].sun -= 200;
			plantCount++;
		}
		else
			cout << "insufficient suns!!!\n";
		break;
	case 5:
		if (users[currentUser].sun >= 150) {
			plants[plantCount] = new snowPea(x, y, plants, plantCount);
			plants[plantCount]->plantText.loadFromFile("Spritesheets/snowpea.png");
			plants[plantCount]->sprite.setTexture(plants[plantCount]->plantText);
			plants[plantCount]->sprite.setPosition(x, y);
			plants[plantCount]->sprite.setTextureRect(IntRect(0, 0, 71, 71));
			//snowCount++;
			users[currentUser].sun -= 150;
			plantCount++;
		}
		else
			cout << "insufficient suns!!!\n";
		break;
	case 0:
		if (users[currentUser].sun >= 100) {
			plants[plantCount] = new sunflower(x, y, plants, plantCount);
			sunCount++;
			plants[plantCount]->plantText.loadFromFile("Spritesheets/sunflower.png");
			plants[plantCount]->sprite.setTexture(plants[plantCount]->plantText);
			plants[plantCount]->sprite.setTextureRect(IntRect(0, 0, 71, 71));

			plants[plantCount]->sprite.setPosition(x, y);
			users[currentUser].sun -= 100;
			plantCount++;
		}
		else
			cout << "insufficient suns!!!\n";
		break;
	case 2:
		if (users[currentUser].sun >= 50) {
			plants[plantCount] = new wallnut(x, y, plants, plantCount);
			wallCount++;
			plants[plantCount]->plantText.loadFromFile("Spritesheets/wallnut.png");
			plants[plantCount]->sprite.setTexture(plants[plantCount]->plantText);
			plants[plantCount]->sprite.setTextureRect(IntRect(0, 0, 71, 71));
			plants[plantCount]->sprite.setPosition(x, y);
			users[currentUser].sun -= 50;
			plantCount++;
		}
		else
			cout << "insufficient suns!!!\n";
		break;
	case 6:
		if (users[currentUser].sun >= 50) {
			plants[plantCount] = new puffshroom(x, y);
			wallCount++;
			plants[plantCount]->plantText.loadFromFile("Spritesheets/sun.png");
			plants[plantCount]->sprite.setTexture(plants[plantCount]->plantText);
			plants[plantCount]->sprite.setTextureRect(IntRect(0, 0, 71, 71));
			plants[plantCount]->sprite.setPosition(x, y);
			users[currentUser].sun -= 50;
			plantCount++;
		}
		else
			cout << "insufficient suns!!!\n";
		break;
	}






}

bool isPlantFarEnough(int x1, int y1, int x2, int y2, int minDistance) {
	int dx = x1 - x2;
	int dy = y1 - y2;
	return (dx * dx + dy * dy) >= (minDistance * minDistance);
}

void plantPlace(sf::RenderWindow& window, sf::Event& event) {
	for (int i = 0; i < level[levelCount].cardsUse; i++) {
		if (cards[i].isSelected) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				int mouseX = sf::Mouse::getPosition(window).x;
				int mouseY = sf::Mouse::getPosition(window).y;

				if (mouseY < 515) {
					// Check if the new plant position is far enough from existing plants
					bool positionValid = true;
					for (int j = 0; j < plantCount; j++) {
						if (!isPlantFarEnough(mouseX, mouseY, plants[j]->getPosX(), plants[j]->getPosY(), minDistance)) {
							positionValid = false;
							break;
						}
					}

					if (positionValid) {
						plantSet(i, mouseX, mouseY);
						cards[i].isSelected = false;
						break;
					}
				}
			}
		}
		else {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				int mouseX = sf::Mouse::getPosition(window).x;
				int mouseY = sf::Mouse::getPosition(window).y;

				if (mouseX > cards[i].Xpos && mouseX < cards[i + 1].Xpos && mouseY > 520) {
					std::cout << "click registered" << i << std::endl;
					std::cout << mouseX << std::endl << mouseY << std::endl;
					for (int j = 0; j < level[levelCount].cardsUse; j++)
						cards[j].isSelected = false;
					cards[i].isSelected = true;
					break;
				}
			}
		}
	}
}


void lawnmowerCreation() {
	for (int i = 0; i < 6; i++) {
		lawnmowers[i].posY = (i * 90) + 10;
		lawnmowers[i].posX = 230;
		lawnmowers[i].text.loadFromFile("gifs/lawnmowerIdle.gif");
		lawnmowers[i].sprite.setTexture(lawnmowers[i].text);
		lawnmowers[i].unused = true;

	}
}
bool isFarEnough(int x1, int y1, int x2, int y2, int minDistance) {
	int dx = x1 - x2;
	int dy = y1 - y2;
	return (dx * dx + dy * dy) >= (minDistance * minDistance);
}

void zombieCreation() {
	std::srand(static_cast<unsigned>(std::time(0))); // Seed the random generator

	for (int i = 0; i < numZombies; i++) {
		// Create different types of zombies
		switch (rand() % 3) {
		case 0:
			zombies[i] = new basic;
			break;
		case 1:
			zombies[i] = new football;
			break;
		case 2:
			zombies[i] = new dancing;
			break;
		}

		bool positionFound = false;
		while (!positionFound) {
			// Generate random position
			int newX = 1300 + (std::rand() % 300);
			int newY = std::rand() % 420;

			// Check against all previously placed zombies
			positionFound = true;
			for (int j = 0; j < i; j++) {
				if (!isFarEnough(newX, newY, zombies[j]->XPos, zombies[j]->Ypos, minDistance)) {
					positionFound = false;
					break; // Generate a new position if too close
				}
			}

			if (positionFound) {
				zombies[i]->XPos = newX;
				zombies[i]->Ypos = newY;
			}
		}

		zombies[i]->damage = 4;
		IntRect zombRect(0, 0, 166, 144);
		zombies[i]->zombSprite.setTextureRect(zombRect);
		zombies[i]->zombSprite.setPosition(zombies[i]->XPos, zombies[i]->Ypos);

	}


	for (int i = 0; i < 4; i++) {

		air[i] = new aerial;
		air[i]->XPos = (1300 + (rand() % 300));
		air[i]->Ypos = (rand() % 500);
		air[i]->zombSprite.setPosition(air[i]->XPos, air[i]->Ypos);

	}
}




//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("Background/bgday.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window, levels l) {
	//Drawing a map

	Image map_image;//объект изображения для карты
	map_image.loadFromFile("Background/bgday.jpg");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);

	window.draw(s_map);
}
void createMenu(RenderWindow& window) {
	Image map_image;
	map_image.loadFromFile("Inventory-GameScreen/ChooserBackground.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);



	s_map.setPosition(0, 600);
	window.draw(s_map);

}


sf::Font font;
sf::Text nameText;
std::string playerName = "";

const string scoreFile = "scores.txt";

bool instruction = false;
bool wait = false;
bool scoreScreen = false;
Clock bulletClock;
float bulletTime = bulletClock.getElapsedTime().asMicroseconds();
int main()
{

	sf::Text scoreText;
	menu1.initializeText(scoreText, font, "Score: 0", 10, 10);
	int userCount = loadScoresFromFile(scoreFile, users);


	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
			level[i].text.loadFromFile("Background/bgday.jpg");
			level[i].levelSprite.setTexture(level[i].text);
			level[i].levelSprite.setPosition(0, 0);
			level[i].cardsUse = 2;
			break;
		case 1:
			level[i].text.loadFromFile("Background/outskirts.png");
			level[i].levelSprite.setTexture(level[i].text);
			level[i].levelSprite.setPosition(0, 0);
			level[i].cardsUse = 3;
			break;
		case 2:
			level[i].text.loadFromFile("Background/field.png");
			level[i].levelSprite.setTexture(level[i].text);
			level[i].levelSprite.setPosition(0, 0);
			level[i].cardsUse = 4;
			break;
		case 3:
			level[i].text.loadFromFile("Background/fog.png");
			level[i].levelSprite.setTexture(level[i].text);
			level[i].levelSprite.setPosition(0, 0);
			level[i].cardsUse = 5;
			break;
		case 4:
			level[i].text.loadFromFile("Background/night.jpg");
			level[i].levelSprite.setTexture(level[i].text);
			level[i].levelSprite.setPosition(0, 0);
			level[i].cardsUse = 6;
			break;
		case 5:
			level[i].text.loadFromFile("Background/limitedbg.png");
			level[i].levelSprite.setTexture(level[i].text);
			level[i].levelSprite.setPosition(0, 0);
			level[i].cardsUse = 7;
			break;

		}
	}

	srand(0);




	int frameWidth = 71; // width of each frame
	int frameHeight = 71; // height of each frame
	int numberOfFrames = 13; // total number of frames in the spritesheet
	float frameTime = 0.15f; // duration each frame is displayed




	RenderWindow window(VideoMode(1400, 687), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{

	}
	window.setIcon(32, 32, icon.getPixelsPtr());



	loadScoresFromFile("scores.txt", users);
	Clock timeMoney;
	lawnmowerCreation();
	Texture map1;
	for (int i = 0; i < 7; i++) {

		switch (i) {
		case 3:
			cards[i].cardText.loadFromFile("Cards/card.png");
			break;
		case 1:
			cards[i].cardText.loadFromFile("Cards/card_peashooter.png");
			break;
		case 4:
			cards[i].cardText.loadFromFile("Cards/card_repeaterpea.png");
			break;
		case 5:
			cards[i].cardText.loadFromFile("Cards/card_snowpea.png");
			break;
		case 0:
			cards[i].cardText.loadFromFile("Cards/card_sunflower.png");
			break;
		case 2:
			cards[i].cardText.loadFromFile("Cards/card_wallnut.png");
			break;
		case 6:
			cards[i].cardText.loadFromFile("Cards/card_scaredyshroom.png");
		}

		cards[i].sprite.setTexture(cards[i].cardText);
		cards[i].Xpos = 70 + (i * 64);
		cards[i].Ypos = 600;
		cards[i].sprite.setPosition(70 + (i * 64), 600);
		cards[i].isSelected = false;
		cards[i].cost = 100;


	}

	Clock clock;

	zombieCreation();


	int currentFrame = 0;
	int zombFrames = 0;


	Texture text1;//объект изображения для карты
	text1.loadFromFile("Background/pause.jpg");//load the file for the map

	Sprite s_map1;
	s_map1.setTexture(text1);
	s_map1.setPosition(0, 0);



	Texture inst;
	inst.loadFromFile("Background/instructions.png");
	Sprite instr;
	instr.setTexture(inst);
	instr.setPosition(0, 0);


	Font font1;
	font1.loadFromFile("fonts/arial.ttf");
	Text score1;
	score1.setFont(font1);
	score1.setFillColor(Color::White);
	score1.setPosition(10, 10);

	Text sun;
	sun.setFont(font1);
	sun.setFillColor(Color::Yellow);
	sun.setPosition(10, 60);

	Texture over;
	over.loadFromFile("GameLoose.png");
	Sprite gameOver;
	gameOver.setTexture(over);
	gameOver.setPosition(400, 200);
	users[0].scoreSort(users);
	Texture pos;
	pos.loadFromFile("first.png");
	Texture pos1;
	pos1.loadFromFile("second.png");
	Texture pos2;
	pos2.loadFromFile("third.png");
	Sprite badges[5];
	badges[0].setTexture(pos);
	badges[1].setTexture(pos1);
	badges[2].setTexture(pos2);
	Text lives;
		menu1.initializeText(lives, font1, "lives : ", 10, 100);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				saveScoresToFile("scores.txt", users, 5);
				window.close();
			}
			menu1.handleTextInput(event, playerName);

			

			// Confirm name entry on Enter key press
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
				//cout << "hallo";

				users[currentUser].name = playerName;
				playerName = "";
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
				currentUser = (currentUser + 1) % 5;
			}
			if (!gameStart) {

				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::G) {
						gameStart = !gameStart;
						cout << "key pressed";
						// Toggle pause state on 'P' key press
					}
					if (event.key.code == sf::Keyboard::S) {
						scoreScreen = !scoreScreen;
					}
					if (event.key.code == Keyboard::I) {
						instruction = !instruction;
					}
				}


			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::P) {
					wait = !wait;  // Toggle pause state on 'P' key press
				}
				if (event.key.code == sf::Keyboard::Escape) {
					saveScoresToFile("scores.txt", users, 5);
					window.close();  // Close the game on 'Escape'
				}
			}
		}

		if (!gameStart) {
			if (!instruction && !scoreScreen && users[currentUser].lives>0) {
				window.draw(menu1.menu1);
				badges[currentUser].setPosition(1100, 50);
				window.draw(badges[currentUser]);
				menu1.initializeText(users[currentUser].scoreText, font1, to_string(users[currentUser].score), 1200, 50);
				users[currentUser].scoreText.setString(users[currentUser].name + " Score: " + std::to_string(users[currentUser].score));
				window.draw(users[currentUser].scoreText);
				window.draw(menu1.playerChange);
				window.display();
			}
			if (!instruction && !scoreScreen && users[currentUser].lives <= 0) {
				window.draw(gameOver);
				window.display();
			}
			if (instruction) {
				window.draw(instr);
				window.display();
			}
			if (scoreScreen) {
				window.draw(scoreboard1.scoreboard1);
				for (int i = 0; i < 5; i++) {
					//window.draw(users[i].text);
					menu1.initializeText(users[i].scoreText, font1, to_string(users[i].score), 600, 200 + (50 * i));
					users[i].scoreText.setString(users[i].name + " Score: " + std::to_string(users[i].score));
					window.draw(users[i].scoreText);
					badges[i].setPosition(500, 200 + (50 * i));
					window.draw(badges[i]);
				}
				window.display();
			}
		}

		if (wait) {



			window.draw(s_map1);
			window.display();
		}
		if (gameStart) {
			if (!wait) {
				float time = clock.getElapsedTime().asMicroseconds();
				float moneyTime = timeMoney.getElapsedTime().asSeconds();

				float deltaTime = clock.restart().asSeconds();
				time = time / 800;




				int zombTime = clock.getElapsedTime().asSeconds();
				//Create a background
				createBack(window);
				window.draw(level[levelCount].levelSprite);
				createMenu(window);


				for (int i = 0; i < level[levelCount].cardsUse; i++) {
					window.draw(cards[i].sprite);
				}

				plantPlace(window, event);


				currentFrame = (currentFrame + 1) % numberOfFrames;

				for (int i = 0; i < 4; i++) {
					if (air[i] != nullptr) {
						if (air[i]->XPos < 50 && air[i]->hitpoints>0) {
							users[currentUser].lives--;
							air[i]->hitpoints = 0;
						}
						air[i]->currentFrame = (air[i]->currentFrame + 1) % air[i]->frames;
						air[i]->zombSprite.setTextureRect(IntRect(air[i]->currentFrame * 166, 0, 166, 144));
						if (air[i]->hitpoints > 0)
							window.draw(air[i]->zombSprite);
						air[i]->move(bulletClock);
						air[i]->zombSprite.setPosition(air[i]->XPos, air[i]->Ypos);
					}
				}


				for (int i = 0; i < 20; i++) {
					bool flag = true;
					zombies[i]->currentFrame = (zombies[i]->currentFrame + 1) % zombies[i]->frames;
					zombies[i]->zombSprite.setTextureRect(IntRect(zombies[i]->currentFrame * 166, 0, 166, 144));

					for (int j = 0; j < 50; j++) {
						if (plants[j] != nullptr && plants[j]->hitpoints > 0)
							if (plants[j]->checkCollision(zombies, i))
							{
								flag = false;
								break;
							}
							else
								flag = true;
					}
					if (flag == true)
						zombies[i]->move(bulletClock);
					bool flag1 = true;
					for (int l = 0; l < 50; l++) {
						if (plants[l] != nullptr && plants[l]->hitpoints > 0) {
							for (int m = 0; m < 4; m++) {
								if (zombies[i]->backup[m] != nullptr)
									if (plants[l]->checkCollision(zombies[i]->backup, m))
									{
										flag1 = false;
										break;
									}
									else
										flag1 = true;
							}

						}


					}
					for (int k = 0; k < 4; k++) {
						if (zombies[i]->backup[k] != nullptr) {
							if (zombies[i]->backup[k]->hitpoints > 0)
								window.draw(zombies[i]->backup[k]->zombSprite);
							for (int n = 0; n < 50; n++) {
								if (plants[n] != nullptr && plants[n]->hitpoints > 0) {

									plants[n]->checkCollision(zombies[i]->backup, k);

									plants[n]->checkSnowBullet(zombies[i]->backup[k]);
									plants[n]->checkRepeatBullet(zombies[i]->backup[k]);
									plants[n]->checkBullet(zombies[i]->backup[k]);

									plants[n]->allahuakbar(zombies[i]->backup, k, 4);
								}
							}
							if (flag1)
								zombies[i]->backup[k]->move(bulletClock);
						}
					}


					zombies[i]->backupSummon(bulletClock, window);
					//cout << "zombie number : "<<i<<" y pos : " << zombies[i].Ypos << endl;
					zombies[i]->zombSprite.setPosition(zombies[i]->XPos, zombies[i]->Ypos);
					if (zombies[i]->hitpoints > 0)
						window.draw(zombies[i]->zombSprite);

				}

				for (int i = 0; i < 6; i++) {
					lawnmowers[i].sprite.setPosition(lawnmowers[i].posX, lawnmowers[i].posY);
					if (!lawnmowers[i].unused)
						lawnmowers[i].posX += 5;
					for (int j = 0; j < 20; j++)
						if (lawnmowers[i].checkCollision(zombies, j)) {
							lawnmowers[i].unused = false;

						}
					if (lawnmowers[i].posX < 1400)
						window.draw(lawnmowers[i].sprite);

				}
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 20; j++)
						if (zombies[j] != nullptr)
							for (int y = 0; y < 4; y++)
								if (zombies[j]->backup[y] != nullptr)
									if (lawnmowers[i].checkCollision(zombies[j]->backup, y)) {
										lawnmowers[i].unused = false;

									}
				}

				for (int i = 0; i < 20; i++)
				{
					if ((zombies[i]->hitpoints == 0 || zombies[i]->hitpoints < 0) && zombies[i]->score == false) {
						users[currentUser].score += 10;
						zombies[i]->score = true;
					}
				}

				for (int i = 0; i < plantCount; i++) {
					if (plants[i] != nullptr && plants[i]->hitpoints > 0) {
						plants[i]->sprite.setTextureRect(IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));

						for (int j = 0; j < 20; j++) {
							plants[i]->allahuakbar(zombies, j, 20);
							plants[i]->checkCollision(zombies, j);

							plants[i]->checkSnowBullet(zombies[j]);
							plants[i]->checkRepeatBullet(zombies[j]);
							plants[i]->checkBullet(zombies[j]);


						}
						plants[i]->repeatFire(window);
						plants[i]->fire(window);
						plants[i]->move();
						plants[i]->sprite.setPosition(plants[i]->posX, plants[i]->posY);
						window.draw(plants[i]->sprite);

					}



				}
				bool allZombDead = true;
				for (int i = 0; i < 20; i++) {
					for (int x = 0; x < 4; x++) {
						//cout << "vaffanculo\n";
						if (zombies[i]->backup[x] != nullptr) {
							if (zombies[i]->backup[x]->XPos < 50) {
								if (zombies[i]->backup[x]->hitpoints > 0) {
									users[currentUser].lives--;
									zombies[i]->backup[x]->hitpoints = 0;
									cout << "you lost a life!!!\n";
								}
							}
						}
					}
					if (zombies[i]->XPos < 50) {
						if (zombies[i]->hitpoints > 0)
						{
							users[currentUser].lives--;
							cout << "you lost a life!!!\n";
							zombies[i]->hitpoints = 0;
						}
					}
				}

				for (int i = 0; i < 20; i++) {
					if (zombies[i]->hitpoints > 0)
						allZombDead = false;
					for (int j = 0; j < 4; j++)
						if (zombies[i]->backup[j] != nullptr)
							if (zombies[i]->backup[j]->hitpoints > 0)
								allZombDead = false;
				}
				if (allZombDead) {
					window.clear();
					levelCount = (levelCount + 1) % 6;
					zombieCreation();
					lawnmowerCreation();
					for (int i = 0; i < 50; i++) {
						plants[i] = nullptr;
					}
					plantCount = 0;
				}
				x = bulletClock.getElapsedTime().asSeconds();

				users[currentUser].sunIncrease(sunCount, x);
				score1.setString("Score : " + to_string(users[currentUser].score));
				lives.setString("Lives : " + to_string(users[currentUser].lives));
				sun.setString("Suns : " + to_string(users[currentUser].sun));
				window.draw(score1);
				window.draw(lives);
				window.draw(sun);
				cout << "suns : " << users[currentUser].sun << endl;
				if (users[currentUser].lives <= 0) {
					gameStart = !gameStart;
					users[currentUser].score = 0;
					window.close();
				}
				window.setSize(sf::Vector2u(1400, 600));

				window.display();
			}
		}

	}

}
