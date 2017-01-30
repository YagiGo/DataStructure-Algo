typedef struct {
    int ord;
    PosType seat;
    int di;
} SElemType;
Status MazePathSearch(MazeType maze, PosType start, PosType end)
{
    InitStack(S);
    PosType curpos = start;
    int curstep = 1;
    while(!StackEmpty(S))
    {
        if(Pass(curpos)) {
            FootPrint(curpos);
            SElemType *e = (curstep,curpos,1);
            push(S,e);
            curpos = nextpos(e.seat,1);
            if(curpos == end) return (TRUE);
        }
        else {
            pop(S,e);
            if(e.di < 4) {
                e.di++; push(S,e); curpos = next(e.seat,e.di);
            }
            while(e.di == 4 && !StackEmpty(S)) {
                Mark(curpos); pop(S,e);
            }
        }
    }
    return FALSE;
}