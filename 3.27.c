#define STACK_INIT_SIZE 255
#define INCREMENT 20
typedef struct {
	int *base;
	int *top;
	int stacksize;
}Stack;
typedef struct {
	int *mval;
	int *nval;
}AKMStack;
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
unsigned int akm(unsigned int m, unsigned int n) {
	if (m == 0) return n + 1;
	else {
		if (n == 0) return akm(m - 1, 1);
		else {
			unsigned int g = akm(m, n - 1);
			return akm(m - 1, g);
		}
	}
}
unsigned int ackerman(unsigned int m, unsigned int n) {
	AKMStack S[top];
	while(top != 0)
	{
		while(S[top].mval) {
			while(S[top].nval) {
				top++; S[top].mval = S[top - 1].mval;
				S[top].nval = S[top - 1].nval - 1; 
			}
			top++; S[top].mval = S[top - 1].mval - 1;
			S[top].nval = 1;
		}

		if(top > 0) {
			top--;
			S[top].mval--;
			S[top].nval = S[top + 1].nval + 1;
		}
	}
	int akm1 = S[top].nval + 1;
	top--;
	return akm1;
}                                      