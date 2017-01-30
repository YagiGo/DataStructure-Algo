#include <math.h>
#define STACK_INIT_SIZE 255
#define INCREMENT 20
#define M 10
#define N 10
#define k 255
typedef struct {
	int *base;
	int *top;
	int stacksize;
}Stack;
void initstack(Stack &S) {
	S.base = (int *)malloc(sizeof(int) * STACK_INIT_SIZE);
	if(!S.base) exit(OVERFLOW);
	S.top = S.base
}
void pop(Stack &S, int e) {
	if(S.base == S.top) exit(NoElement);
	e = *(--S.top);
	return e;
}
void push(Stack &S, int e) {
	if(S.top - S.base == stacksize) {
		S.base = (int *)remalloc(sizeof(int) * (STACK_INIT_SIZE + INCREMENT));
		S.top = S.base + stacksize;
		S.stacksize += INCREMENT;
	}
	*(S.top) = e;
	S.top++;
}
stackempty(Stack &S)
{
	if(S.stacksize == 0) return 1;
	else return 0;
}
int ditui1(int m, int n,) {
	if(m == 0) return 0;
	else return ditui1(m - 1, 2 * n) + n;
	}
double ditui3(double A, double p, double e) {
	if(abs(pow(p,2) - A) < e) return p;
	else return ditui3(A, 0.5 * (p + A/p), e);
}
double sqrt(double A, double p, double e) {
	p = 1/2 (p + A/p);
	while(abs(pow(p,2) - A) >= e) p = 1/2 (p + A/p);
	return p;
}

 
