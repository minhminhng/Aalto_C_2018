#include <stdio.h> 
#include <math.h>  
double vectorlength(double i, double j, double k) 
{ 
	return sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2)); 
}  

int main(void) 
{
	printf("%f",vectorlength(1, 3, 5)); 
	return 0;
}

