#include <stdio.h>
#include <ctype.h>

void ascii_chart(char min, char max)
{
	unsigned int j = 0;
	for (unsigned int i = min; i < max + 1; i++)
	{
		// Check if the character is printable
		if (isprint(i))
		{
			printf("%3d 0x%02x %c",i,i,i);
		}
		else
		{
			printf("%3d 0x%02x %c",i,i,63);
		}
		// Check for the current line
		if (j < 3) 
		{
			printf("\t");
			j++;
		}
		else 
		{
			printf("\n");
			j = 0;
		}
	}
}

int main(void)
{
	ascii_chart(1, 38);
	return 0;
}
