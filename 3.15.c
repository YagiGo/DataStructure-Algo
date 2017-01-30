#define STACK_INIT_SIZE 100;
typedef struct {
	int *frontbase;
	int *fronttop;
	int *rearbase;
	int *reartop;
	int stacksize;
}DStack;
void inistack(DStack &tws) {
	tws.frontbase = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	tws.fronttop = tws.frontbase;
	tws.rearbase = tws.frontbase + STACK_INIT_SIZE; tws.reartop = tws.rearbase; 
	tws.stacksize = STACK_INIT_SIZE;
}
void pop(DStack &tws, int e, int i) {
	if(i == 0) {
		e = *(--tws.fronttop); 
	}
	else {
		e = *(++tws.reartop);
	}
}
void push(DStack &tws, int e, int i) {
	if(tws.reartop - tws.fronttop == 1) exit(STACKFULL);
	if(i == 0) {
		*(tws.fronttop) = e;
		tws.fronttop++;
	}
	else {
		*(tws.rearbase) = e;
		tws.reartop--;
	}
}

