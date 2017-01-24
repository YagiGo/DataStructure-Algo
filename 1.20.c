#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 10
int main()
{
	int x = 2;result;//count 1
	int a[9] = [2,3,5,4,3,2,3,2,1,4]; //count 1
	for(i = 0; i < n; i++)
	{
		result += a[i] * pow(x,i); //count n
	}
	printf("Result: %d\n",result); //count 1
}
// O(n)