#define MAXLEN 10
#define max 100
typedef struct {
	int *base;
	int startADDR;
	int length;
	int stacksize;
	int head;
	int rear;
}CircleStack;
//循环序列栈满的条件 S.rear == S.head && S.length == MAXLEN;
void initstack(CircleStack &S)
{
	S.base = (int *)malloc(sizeof(int) * MAXLEN);
	S.startADDR = S.base;
	if(!S.base) exit(OVERFLOW);
	S.head = S.rear = 0;
	S.stacksize = MAXLEN;
	S.length = 0;
}
push(CircleStack &S, int e) {
	if((s.base - S.startADDR) == MAXLEN)  S.base = S.startADDR;
	*(S.base) = e;
	S.base++;
	S.rear = (S.rear + 1) % MAXLEN;
	if(S.length == MAXLEN) continue;
	else S.length++;
}
pop(CircleStack &S, int e) {
	if(S.head == S.rear && S.length == 0) exit(STACKEMPTY)
	e = *(S.base - S.length);
	S.length --;
	S.head++;
}
int fibonacci(CircleStack &S)  
{
	push(S,0);
	push(S,1);
	int e1, e2;
	pop(S,e1); pop(S,e2);
	int e = e1 + e2;
	while(e <= max){
		push(S,e);
		pop(S,e1); pop(S,e2);
		e = e1 + e2; 
	}
	return e;
}
void main()
{
	CircleStack S;
	initstack(S);
	fibonacci(S);
}
