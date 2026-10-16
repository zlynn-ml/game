#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

inline int pers_HP = 100;
inline int keys;
inline int i = 12, j = 2;
inline bool game = true;
void fight(int* keys, int* pers_HP);
inline int key = 0;

inline int game_map[15][15] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 2, 0, 1, 1, 0, 1, 1, 0, 0, 3, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 4, 0, 0, 1, 1, 0, 1, 1, 0, 0, 2, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

inline int win[15][15]{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

inline void set_cursor_position(int x, int y) {
	
    COORD coord = { (SHORT)x, (SHORT)y };
	
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 

inline void draw_map(int game_map[15][15]) {
	
    set_cursor_position(0, 0); 
    
    cout << "\n\n\n\n\n\n";
    
    for (int i = 0; i < 15; i++) {
        cout << "                                                    ";
        
        for (int j = 0; j < 15; j++) {
            switch (game_map[i][j]) {
                case(0): {
                    cout << "  ";
                    break;
                }
                case(1): {
                    cout << "██";
                    break;
                }
                case(2): {
                    cout << "BB";
                    break;
                }
                case(3): {
                    cout << "$$";
                    break;
                }
                case(4): {
                    cout << "@@";
                    break;
                }
            }
        }

        if (i == 7 && key == 1) { 
            cout << "    you need 2 keys";
        } 
		else {
            cout << "                   "; 
        }
        
        cout << endl;
    }
    
    if (key == 1) {
        key = 0;
    }

    return;
}

inline void move(int game_map[15][15], int* i, int* j, bool* game, int* keys, int *pers_HP, int * key) {
	char wasd;
	bool fw = false;

	while (fw == false) {
		cin >> wasd;

		switch (wasd) {

		case('w'):
		case('W'): {
			if (game_map[*i - 1][*j] == 0) {
				game_map[*i - 1][*j] = 4;
				game_map[*i][*j] = 0;
				fw = true;
				(*i)--; 
				break;
			}
			else if (game_map[*i - 1][*j] == 1)
				break;
			else if (game_map[*i - 1][*j] == 2) {
				fight(&*keys, &(*pers_HP));
				fw = true;
			    game_map[*i - 1][*j] = 4;
				game_map[*i][*j] = 0;
				(*i)--;
				break; 
			}
			else if (game_map[*i - 1][*j] == 3) {

				if (*keys == 2) {
					cout << "you win!";
					draw_map(win);
					*game = false;
					fw = true;
				}
				else
					*key = 1;
				break;
			}
		}

		case('a'):
		case('A'): {
			if (game_map[*i][*j-1] == 0) {
				game_map[*i][*j-1] = 4;
				game_map[*i][*j] = 0;
				fw = true;
				(*j)--;
				break;
			}
			else if (game_map[*i][*j-1] == 1)
				break;
			else if (game_map[*i][*j-1] == 2) {
				fight(&*keys, &(*pers_HP));
				fw = true;
				game_map[*i][*j-1] = 4;
				game_map[*i][*j] = 0;
				(*j)--;
				break;
			}
			else if (game_map[*i][*j-1] == 3) {

				if (*keys == 2) {
					cout << "you win!";
					draw_map(win);
					*game = false;
					fw = true;
				}
				else
					*key = 1;
				break;
			}
		}
		case('s'):
		case('S'): {
			if (game_map[*i + 1][*j] == 0) {
				game_map[*i + 1][*j] = 4;
				game_map[*i][*j] = 0;
				fw = true;
				(*i)++;
				break;
			}
			else if (game_map[*i + 1][*j] == 1)
				break;
			else if (game_map[*i + 1][*j] == 2) {
				fight(&*keys, &(*pers_HP));
				fw = true;
				game_map[*i + 1][*j] = 4;
				game_map[*i][*j] = 0;
				(*i)++;
				break;
			}
			else if (game_map[*i + 1][*j] == 3) {

				if (*keys == 2) {
					cout << "you win!";
					draw_map(win);
					*game = false;
					fw = true;
				}
				else
					*key = 1;
				break;
			}
		}
		case('d'):
		case('D'): {
			if (game_map[*i][*j+1] == 0) {
				game_map[*i][*j+1] = 4;
				game_map[*i][*j] = 0;
				fw = true;
				(*j)++;
				break;
			}
			else if (game_map[*i][*j+1] == 1)
				break;
			else if (game_map[*i][*j+1] == 2) {
				fight(&*keys, &(*pers_HP));
				fw = true;
				game_map[*i][*j+1] = 4;
				game_map[*i][*j] = 0;
				(*j)++;
				break;
			}
			else if (game_map[*i][*j+1] == 3) {

				if (*keys == 2) {
					cout << "you win!";
					draw_map(win);
					*game = false;
					fw = true;
				}
				else
					*key = 1;
				break;
			}
		}

		}

		return;
	}
}


inline void fight(int* keys, int * pers_HP) {
	int hp_boss = 150;
	char attack;
	int ult = 0;
	int num = 0;
	char h;

	while(*pers_HP > 0){

		system("cls");
		cout << "     fight\n\n\n      E - Attack, R - Ulta\n";

		if (hp_boss < 0) {

			*keys += 1;
			cout << "\nTHE BOSS HAS BEEN DEFEATED!\n";
			return;
		}
		else {

			cout << "\n     Boss HP: " << hp_boss << "\n     your HP: " << *pers_HP << endl << endl;

			if (num == 2) {
				cout << "    BOSS Attacked\n      damage: " << (rand() % 3 + 1) * 4;
				*pers_HP = *pers_HP - (rand() % 3 + 1) * 4;
				num = 0;
				cin >> h;
			}
			else{

			cin >> attack;

			switch (attack) {

			case('e'):
			case('E'): {
				hp_boss -= (rand() % 3 + 1) * (rand() % 3 + 1) + (rand() % 3 + 1) * (rand() % 3 + 1);
				num++;
				ult++;
				break;
			}
			case('r'):
			case('R'): {
				if (ult > 2) {
					hp_boss -= (rand() % 3 + 1) * ((rand() % 3 + 1) * (rand() % 3 + 1) + (rand() % 3 + 1) * (rand() % 3 + 1));
					num++;
					break;
				}
				else
					break;
			}
			}
			}
		}

	}
	cout << "you loose!";
	game = false;
}
