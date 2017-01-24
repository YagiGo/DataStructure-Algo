#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
    int *elem;
    int length;
    int listsize;
} SqList;

typedef struct {
    struct LNode *next;
    int data;
} LNode, *LinkList;