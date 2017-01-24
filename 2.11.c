#include <ListStructure.h>
void Insert(SqList &List, int &x)
{
   SqList *a = List;
   if(a.length == a.listsize) return OVERFLOW
   for(i = 0; i < a.length; i++)
   {
       if(x >= a.elem[i])
       {
           for(j = a.length - 1; j > i; j--)
           {
               a.elem[j + 1] = a.elem[j];
           }
           a.elem[i + 1] = x;
           a.length++;
           return OK
       }                                                                                                                                                                                                                                                                             
   }
}