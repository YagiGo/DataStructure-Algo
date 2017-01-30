#define MAXLEN 100
typedef struct {
	int *base;
	int length;
	int stacksize;
	int head;
	int rear;
}CircleStack;
//循环序列栈满的条件 S.rear == S.head && S.length != 0;
void initstack(CircleStack &S)
{
	S.base = (int *)malloc(sizeof(int) * MAXLEN);
	if(!S.base) exit(OVERFLOW);
	S.head = S.rear = 0;
	S.stacksize = MAXLEN;
	S.length = 0;
}
push(CircleStack &S, int e) {
	*(S.base) = e;
	S.base++;
	if(s.rear == S.head && S.length == MAXLEN) exit(STACKFULL);
	S.rear = (S.rear + 1) % MAXLEN;
	S.length++;
}
pop(CircleStack &S, int e) {
	if(S.head == S.rear && S.length == 0) exit(STACKEMPTY)
	e = *(S.base - S.length);
	S.length --;
	S.head++;
}
