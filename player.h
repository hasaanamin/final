#pragma once
class player {
	public:
		float sun = 2000;
		int lives = 3;
		int position = 0;
		string name = "player1";
		Text text;
		Text scoreText;
		int score=0;
		void sunIncrease(int i, int x) {
			
			if ((x % 10) == 0) {
				sun += 2 + (i * 0.5);
				
			}
		}
		void scoreSort(player users[]) {
			for (int i = 0; i < 5 - 1; ++i) {
				for (int j = 0; j < 5 - i - 1; ++j) {
					if (users[j].score < users[j + 1].score) {
						// Swap users[j] and users[j + 1]
						player temp = users[j];
						users[j] = users[j + 1];
						users[j + 1] = temp;
					}
				}
			}

			// Update positions based on sorted order
			for (int i = 0; i < 5; ++i) {
				users[i].position = i + 1;
			}
		}

};