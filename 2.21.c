#include <ListStructure.c>
void reverse(SqList &l)
{
    n = l.length;
        if(n % 2 ==0)
        {
            for(i = 0; i < n/2; i++)
            {
                a.elem[n-1-i] = a.elem[n-1-i] + a.elem[i];
                a.elem[i] = a.elem[n-1-i] - a.elem[i];
                a.elem[n-1-i] = a.elem[n-1-i] - a.elem[i];
            }
        }
        else
        {
             for(i = 0; i < (n-1)/2; i++)
            {
                a.elem[n-1-i] = a.elem[n-1-i] + a.elem[i];
                a.elem[i] = a.elem[n-1-i] - a.elem[i];
                a.elem[n-1-i] = a.elem[n-1-i] - a.elem[i];
            }
        }
    }
}