#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fraction.h"

/* Algorithm for determining greatest common divisor, needed in (d) */
/* The function returns gcd between the two parameters, u and v */
/* Taken from http://en.wikipedia.org/wiki/Binary_GCD_algorithm */
unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
 
    return gcd((v - u) >> 1, u);
}

Fraction* setFraction(unsigned int numerator, unsigned int denominator)
{
	if (denominator == 0){
		printf("Denominator can not be 'zero'.");
		return NULL;
	}
	Fraction *newFraction = malloc(sizeof(Fraction));
	if (newFraction == NULL){
		return NULL;
	}
	newFraction -> numerator = numerator;
	newFraction -> denominator = denominator;
	return newFraction;
}

/* Returns the numerator of the given fraction */
unsigned int getNum(const Fraction *f)
{
	return f -> numerator;
}

/* Returns the denominator of the given fraction */
unsigned int getDenom(const Fraction *f)
{
	return f -> denominator;
}

/* Releases the Fraction from heap */
void freeFraction(Fraction *f)
{
	assert(f);
	free(f);
}

/* Compares two fractions */
int compFraction(const Fraction *a, const Fraction *b)
{
	int a1 = a -> numerator * b -> denominator;
	int a2 = b -> numerator * a -> denominator;
	if (a1 < a2){
		return -1;
	}
	else if( a1 == a2){

		return 0;
	}
	else {
		return 1;
	}
}

/* Adds the given fractions and creates new object for the result */
Fraction* addFraction(const Fraction *a, const Fraction *b)
{
	return setFraction(a -> numerator * b -> denominator + 
			a -> denominator * b -> numerator, a -> denominator * b -> denominator);
}

/* Reduce fraction */
void reduceFraction(Fraction *val)
{
	unsigned int comm = gcd(val -> numerator, val -> denominator);
	val -> numerator = val -> numerator / comm;
	val -> denominator = val -> denominator / comm;
}

/* Print fraction (optional, does not give points) */
void printFraction(const Fraction *val)
{
	printf("Your fraction is %d/%d.\n", val -> numerator, val -> denominator);
}



