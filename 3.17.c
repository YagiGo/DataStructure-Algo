#define STACK_INIT_SIZE 255
#define BUFFERSIZE 255
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
void stackempty(Stack &S)
{
	if(S.stacksize == 0) return 1;
	else return 0;
}
void stringcheck()
{
	Stack S;
	char buffer1[BUFFERSIZE], buffer2[BUFFERSIZE];
	char c,e;
	while((c = getchar()) != '\n')  push(S,c);
	pop(S,e);
	while(!stackempty(S) && e !='&') {
		for(i = 0; i < BUFFERSIZE; i++) {
			buffer1[i] = e; pop(S,e);
		}
	}
	while(!stackempty(S)) {
		for(j = 0; i < BUFFERSIZE; j++) {
			pop(S,e); buffer2[j] = e; 
		}
	}
	while(j >= 0) {
		int i = 0;
		if (buffer2[j] == buffer1[i]) j--;i++;
		else { printf("NOT MATCHED! \n"); exit(); }
	}
	if((i+1) == strlen(buffer1)) printf("MATCHED! \n");
	else printf("UNMATCHED! \n");
}