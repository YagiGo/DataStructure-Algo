#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXINT
#define arrsize
int factorial(int x)
{
	if(x == 0) return 1;
	int result;
	for(i = 1; i <= x; i ++)
	{
		result *= i;
	}
	return result;
}
int calculate(int n)
{
	int a[arrsize];
	if(n > arrsize) {printf("n is not allowed!\n"); exit();}
	for(i = 0; i < n; i++)
	{
		int c;
		c = factorial(i)*pow(2,i);
		if(c > MAXINT) {printf("Result not allowed!\n"); exit();}
		a[i] = c;
	}
}