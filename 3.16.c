#define STACK_INIT_SIZE 255
#define INCREMENT 20
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
void trainmove()
{
	Stack S;
	int buffer[255];
	initstack(S);
	// 1 stands for H  while 2 stands for S 0 stands for Stop
	int x;
	scanf(x);
	while(x != 0)
	{
		push(S,x);
		scanf(x);
	}
	while(!stackempty(S)) {
		for(i = 0; i < 255; i ++) {
			int e;
			pop(S,e); buffer[i];
		}
	}
	int j = 0
	while(j < j) {
		push(S,buffer[j]); j++;
	}
}
