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
void fillingcolor(int g[M][N])
{
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j++)
		{
			int color = rand() % k;
			g[i][j] = color;
		}
	}
}
void changecolor(int g[M][N], int changedcolor, int i0, int j0)
{
	g[i0][j0] = changedcolor;
	g[i0][j0-1] = changedcolor;
	g[i0][j0+1] = changedcolor;
	g[i0-1][j0] = changedcolor;
	g[i0+1][j0] = changedcolor;
}
void show(g[M][N])
{
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			printf("%3d\n",g[i][j] );
		}
		printf("\n");
	}
}
void main()
{
	int map[M][N], i0, j0, changedcolor;
	fillingcolor(map[M][N]);
	printf("MAP: \n");
	show(map[M][N]);
	printf("请输入想要改变颜色的位置坐标使用逗号隔开如 2,3：\n")
	scanf("%d,%d", &i0,&j0);
	printf("请输入想要改变的颜色（0-255）：\n");
	scanf("%d", &changedcolor);
	changecolor(map[M][N], changedcolor, i0, j0);
	printf("After:\n");
	show(map[M][N]);
}
