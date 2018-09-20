#include <stdio.h>


void simple_multiply(void)
{
	int num1 = 0, num2 = 0;
	//printf("Please input two integers: ");
	scanf("%d %d", &num1, &num2);
	printf("%d * %d = %d\n",num1, num2, num1 * num2);
}

void simple_math(void)
{
	float num1 = 0, num2 = 0;
	char op = 0;
	//printf("Please input two values and an operand: ");
	int ret = scanf("%f %c %f", &num1, &op, &num2);
	//printf("%g", num2);
	/*** without initialize and if num2 is not an integer, the program 
	 * returns error ***/
	
	if (ret == 3){
		switch (op) {
			case '+':
				//printf("%g %c %g (user input)\n", num1, op, num2);
				printf("%.1f\n", num1 + num2);
				break;
			case '-':
				//prntf("%g %c %g (user input)\n", num1, op, num2);
				printf("%.1f\n", num1 - num2);
				break;
			case '*':
				//printf("%g %c %g (user input)\n", num1, op, num2);
				printf("%.1f\n", num1 * num2);
				break;
			case '/':
				//printf("%g %c %g (user input)\n", num1, op, num2);
				if (num2 == 0.0)
				{
					printf("ERR");
				}
				else
				{
					printf("%.1f\n", num1 / num2);
				}
				break;
			default:
				printf("ERR\n");
		}
	}
	else
	{
		printf("ERR\n");
	}
}
int main(void)
{
	simple_multiply();
	simple_math();
	return 0;
}
