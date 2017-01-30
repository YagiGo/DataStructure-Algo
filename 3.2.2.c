void BracketCheck()
{
    InitStack(s);
    char ch = getchar();
    while(ch != EOF) {
        switch(ch) {
        case ch = '[': push(s,ch);
        case ch = '(': push(s,ch);
        case ch = ']': GetPop(s,e); if(e == '(') return Illegal; else if(e == '[') pop(s); 
        case ch = ')': GetPop(s,e); if(e == '[') return Illegal; else if(e == '()') pop(s); 
        }
        ch = getchar();
    }
}
void LineEdit()
{
    InitStack(s);
    char ch = getchar();
    while(ch != EOF)
    {
        switch(ch) {
            case ch = '#': pop(s,c);
            case ch = '@': clearstack(s);
            defalut: push(s,ch);
        }
    ch = getchar();
    }
}