#include <stdio.h>

void draw_triangle(unsigned int size)
{
	for (unsigned int i = 0; i < size; i++){
		for (unsigned int j = 0; j < size-i-1; j++){
			printf(".");			
		}
		for (unsigned int j = 0; j < i + 1; j++){
			printf("#");
		}
		printf("\n");
	}
}

int main(void)
{
	while (1)
	{
		unsigned int s = 0;
		printf("Input a value:");
		scanf("%u", &s);
		draw_triangle(s);
	}
	return 0;
}
