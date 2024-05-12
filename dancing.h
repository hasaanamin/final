#pragma once
#include"zombie.h"
#include"basic.h"
class dancing :public Zombies {
	
public:
	
	dancing() {
		for (int i = 0; i < 4; i++)
			backup[i] = nullptr;
		zombText.loadFromFile("Spritesheets/nZombEat.png");
		zombSprite.setTexture(zombText);
		frames = 19;
		speed = 2;
		hitpoints = 15;
		direction = 1;
		
	}
	void backupSummon(Clock t1, RenderWindow& window) {
		int c = t1.getElapsedTime().asSeconds();
		srand(0);
		if ((c % 5) == 0 && backupCount < 4) {
			backup[backupCount] = new basic((XPos + (rand()%120)), (Ypos + (rand() % 120)));
			backupCount++;
			//cout << "hallo\n";
			
		}
		for (int i = 0; i < backupCount; i++) {
			if (backup[i] != nullptr) {
				backup[i]->XPos = (XPos + (rand() % 80));
				backup[i]->Ypos = (Ypos + (rand() % 80));
				backup[i]->currentFrame = (backup[i]->currentFrame + 1) % 20;
				backup[i]->zombSprite.setTextureRect(IntRect(backup[i]->currentFrame * 166, 0, 166, 144));
				backup[i]->zombSprite.setPosition(backup[i]->XPos, backup[i]->Ypos);
				//window.draw(backup[i]->zombSprite);
			}

		}
	}

	void move(Clock t1) {
		Ypos =Ypos - (direction * speed);
		XPos -= speed;
		if (Ypos > 400 || Ypos < 10)
			direction = direction * -1;




	}
};
