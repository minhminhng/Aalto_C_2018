#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aaltogame.h"

unsigned int point(unsigned int ysize, unsigned int x, unsigned int y)
{
	return y*ysize + x;
}

Area *createArea(unsigned int xsize, unsigned int ysize)
{
	Area *newArea = malloc(sizeof(Area));
	newArea -> xsize = xsize;
	newArea -> ysize = ysize;
	if(!newArea){
		return NULL;
	}
	newArea->cells = malloc(ysize * sizeof(Status *));
	//printf("A new area was created.\n");
	if(!newArea->cells){
		free(newArea);
		return NULL;
	}
	//printf("New cells was created.\n");
	for (unsigned int j = 0; j < ysize; j++){
		newArea->cells[j] = malloc(xsize * sizeof(Status));
		if(!newArea->cells[j])
		{
			for (unsigned int i = 0; i < j; i++){
				free(newArea->cells[i]);
			}
			free(newArea->cells);
			free(newArea);
			return NULL;
		}
		
		for (unsigned int i = 0; i < xsize; i++){
			newArea->cells[j][i] = DEAD;
			//printf("%d", newArea->cells[j][i]);
		}
		//printf("Cells were assigned new states.\n");
	}
	return newArea;
}

void releaseArea(Area *a)
{
	for (unsigned int j = 0; j < a->ysize; j++){
		free(a->cells[j]);
	}
	free(a->cells);
	free(a);
}

void initArea(Area *a, unsigned int n)
{
	int alive[1000];
	unsigned int inList = 0;
	for (unsigned int i = 0; i < n;)
	{
		unsigned int new = rand() % (a->xsize * a->ysize);
		for (unsigned int j = 0; j < i; j++)
		{
			if (new == alive[j]){
				inList = 1;
			}
		}
		if (!inList){
			alive[i] = new;
			printf("%d ", alive[i]);		// test if the position is already alive
			i++;
		}
		inList = 0;
	}
	printf("\n");
	
	for (unsigned int i = 0; i < n; i++){
		//printf("%d ", alive[i]/a->ysize);		
		int y = alive[i] % a->ysize;	
		//printf("%d ", y);
		a->cells[y][alive[i]/a->ysize] = ALIVE;
	}
}

void printArea(const Area *a)
{
	for (unsigned int j = 0; j < a->ysize; j++){	
		for(unsigned int i = 0; i < a->xsize; i++){
			if (a->cells[j][i] == DEAD){
				printf(".");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}

unsigned int liveNeighbors(Area *a, unsigned int posx, unsigned int posy)
{
	unsigned int neighbors = 0;
	unsigned int xmin, xmax, ymin, ymax;
	if (posx == 0){
		xmin = 0;
	}
	else{
		xmin = posx - 1 ;
	}
	if (posx == a->xsize - 1){
		xmax = a->xsize;
	}
	else {
		xmax = posx + 2;
	}
	
	if (posy == 0){
		ymin = 0;
	}
	else{
		ymin = posy - 1 ;
	}
	if (posy == a->ysize - 1){
		ymax = a->ysize;
	}
	else {
		ymax = posy + 2;
	}

	for (unsigned int j = ymin; j < ymax; j++){
		for (unsigned int i = xmin; i < xmax; i++){	
			//printf("%d %d   %d %d  %d \n", j, i, posx, posy, a->cells[j][i]);
			if (a->cells[j][i] == ALIVE && (i!= posx || j!=posy))
			{
				neighbors++;
			}
		}
	}
	return neighbors;
}
void assignA(Area *a, int new[])
{
	for (unsigned int j = 0; j < a->ysize; j++){
		for (unsigned int i = 0; i < a->xsize; i++){
			unsigned int pos = point(a->ysize, j, i);
			a->cells[j][i] = new[pos];
		}
	}
}

void tick(Area *a)
{
	unsigned int size = a->xsize * a->ysize;
	int new[1000];
	memset(new, 0, size*sizeof(int));
	for (unsigned int j = 0; j < a->ysize; j++){
		for (unsigned int i = 0; i < a->xsize; i++){	
			unsigned int live = liveNeighbors(a, i, j);
			//printf("%d \n", live);
			//printArea(a);
			unsigned int pos = point(a->ysize, j, i);
			if (live == 3){
				new[pos] = ALIVE;
			}
			else if(live < 2 || live > 3){
				new[pos] = DEAD;
			}
			else if (a->cells[j][i] == ALIVE && live == 2){
				new[pos] = ALIVE;
			}
			else if (a->cells[j][i] == DEAD && live == 2){
				new[pos] = DEAD;
			}
			//printf("%d \n", new[pos]);
			//printf("\n");

		}
	}
	assignA(a, new);
}
