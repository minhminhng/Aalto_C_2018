#include <stdio.h>
#include "aaltogame.h"


/* 
 * Game of life 
 * https://en.m.wikipedia.org/wiki/Conway%27s_Game_of_Life
 * */
int main(void)
{
	Area *newGame;
	newGame = createArea(5,5);
	initArea(newGame, 6);
	printArea(newGame);
	printf("~~~ START ~~~\n");
	for (unsigned int i = 0; i < 3; i++){
		tick(newGame);
		printArea(newGame);
		printf("\n");
	}
	releaseArea(newGame);
	return 0;
}
