#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
typedef struct CSNode {
	char data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
void AddNode(CSNode *parent, CSNode *child)
{
	if((parent->firstchild) != NULL)
	{
		parent->firstchild->nextsibling = child;
	}
	else parent->firstchild = child;
}
void PreOrder(CSTree T)
{
	if(T) {
		printf("%c",T->data);
		PreOrder(T->firstchild);
		PreOrder(T->nextsibling);
	}
}
void InOrder(CSTree T)
{
	if(T) {
		PreOrder(T->firstchild);
		printf("%c",T->data);
		PreOrder(T->nextsibling);
	}
}
void PostOrder(CSTree T)
{
	if(T) {
		PreOrder(T->firstchild);
		PreOrder(T->nextsibling);
		printf("%c",T->data);
	}
}
int main()
{
	int i, num = 9;
	char ch = 'A';
	CSTree node;
	node = malloc(num * sizeof(CSNode));
	for(i = 0; i < num; i++) {
		node[i].data = ch;
		node[i].firstchild = NULL;
		node[i].nextsibling = NULL;
		ch++;
	}
	AddNode(&node[0],&node[1]);     // A->B 
    AddNode(&node[0],&node[2]);     // A->C  
    AddNode(&node[1],&node[3]);     // B->D  
    AddNode(&node[1],&node[4]);     // B->E  
    AddNode(&node[2],&node[5]);     // C->F  
    AddNode(&node[3],&node[6]);     // D->G  
    AddNode(&node[5],&node[7]);     // F->H  
    AddNode(&node[5],&node[8]);     // F->I

    printf("前序遍历： ");  
    PreOrder(&node[0]);  
    printf("\n");  
  
    printf("中序遍历： ");  
    InOrder(&node[0]);  
    printf("\n");  
  
    printf("后序遍历： ");  
    PostOrder(&node[0]);  
    printf("\n");  
    return 1;  
}  
