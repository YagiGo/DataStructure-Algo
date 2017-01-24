#include <ListStructure.h>
Status DeleteAndInsert(LinkList la, LinkList lb, int i, int j, int len)
{
    if(i < 0 || j < 0 || len < 0) return UNFEASIBLE;
    LinkList p = la; int k = 1;
    while (k < i) 
    {   LinkList prev = p;
        p = p -> next;
        k++;
    }
    LinkList q = p;
    while(k <= len && (q -> next) != NULL) //Changed!
    {  
        q = q -> next; 
        k++;
    }
    if((q -> next)) printf("REACHED the End of the LIST\n");
    LinkList s = lb; k = 1;
/* Changed Part */
    if(j == 1)
    {
        q -> next = lb;
        lb = p; //J=1 
    }
/* Change Part */
    while(k < j && s != NULL)
    {
        s = s -> next; k++;
    }
    if(s == NULL) return INFEASIBLE;
    prev -> next = q; //Delete
    q -> next = s -> next;
    s -> next = p;

    return OK;
}