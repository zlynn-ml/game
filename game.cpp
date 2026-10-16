#include "game.h"
int main() {

	srand(time(0));
	system("chcp 65001");

	while (game) {

		draw_map(game_map);

		move(game_map, &i, &j, &game, &keys, &pers_HP, &key);
	}

	return 0;
}