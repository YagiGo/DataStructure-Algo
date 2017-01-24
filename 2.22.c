#include <ListStructure.c>
void LinkListReverse(LinkList &l)
{
    LinkList h = l -> next; p = l;
    LinkList pres = h; //save the first data
    while((p -> next -> next) != NULL) {
        LinkList prior = p;
        p = p -> next;
        }
    prior -> next = p -> next;
    p -> next = h;
    h = p;
    }
    while(prior != pres) {
        p = pres;
        while(p -> next -> next != NULL) {
            p = p -> next;
        }
        prior -> next = p -> next;
        p -> next = pres;
        h -> next = p;
        h = p;
    }
}