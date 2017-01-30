struct QNode {
    QElemType data;
    struct QNode *next;
}
struct LNode{
    int data;
    struct LNode *next; 
}
struct LinkQueue {
    QueuePtr front;
    QueuePtr rear;
}
struct Event {
    int OccurTime;
    int NType;
}
typedef struct {
    int ArrivialTime;
    int Duration;
}QElemType;
typedef struct QNode *QueuePtr;
typedef struct LNode *EventList, *LinkList;
typedef struct LinkQueue LinkQueue;
typedef struct Event Event;
void InitQueue(LinkQueue &Q) {
    Q.rear = Q.front = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) exit(OVERFLOW);
    Q.front -> next = NULL;
}
void DestroyQueue(LinkQueue &Q) {
    while(Q.rear) {
        Q.rear = Q.front -> next;
        free(Q.front);
        Q.front = Q.rear;
    }
}
void EnQueue(LinkQueue &Q, QElemType e) {
    p = (QueuePtr)malloc(sizeof(QNode));
    p.data = e; p -> next = NULL;
    Q.rear -> next = p;
    Q.rear = p;
}
void DeQueue(LinkQueue &Q, QElemType &e) {
    if(Q.rear == Q.front) exit(ERROR);
    p = (QueuePtr)malloc(sizeof(QNode));
    p = Q.front -> next;
    e = p.data;
    Q.front ->next = p -> next;
    if(Q.rear == p) Q.rear = Q.front;
    free(p);
}
void OrderInsert(LinkList &L, Event e, int(*cmp)());
EventList ev; //事件表
Event en;//插入时间表的时间：事件发生时间和事件类型
LinkQueue q[5]; //4个队列
QElemType customer; //队列内的顾客的详细信息：到达时间和持续时间
int TotalTime, CustomerNum;
int cmp(Event a, Event b);
void OpenForBusiness()
{
    TotalTime = 0; CustomerNum = 0;//总等待时间为0.顾客人数为0
    InitList(ev);//初始化事件链表
    en.OccurTime = 0; en.NType = 0; //事件发生时间为0，事件类型：顾客到达
    OrderInsert(ev,en.cmp);//插入事件表
    for(i = 1; i <= 4; i ++) InitQueue(q[i]); //1-4的队列全部初始化
}
void CustomerArrived()
{
    en.NType = 0; ++CustomerNum; //事件类型：顾客到达， 顾客人数+1
    int durtime, intertime; //顾客的业务持续时间和两个顾客之间的间隔时间
    Random(durtime, intertime);
    int t = en.OccurTime + intertime;
    if(t < CloseTime) OrderInsert(ev, (t,0), cmp); //插入顾客到达时间
    i = Minimun(q)//最短的一列
    EnQueue(q[i], (en.OccurTime + durtime, i), cmp);//顾客进入最短的一列排队
}
void CustomerDeparture() 
{
    i = en.Ntype; DeQueue(q[i], customer);
    TotalTime += en.OccurTime - customer.ArrivialTime; //单个顾客的总花费时间累加得到总时间
    if(!QueueEmpty(q[i])) {
        GetHead(q[i], customer);
        OrderInsert(&ev, (en.OccurTime + customer.Duration, i), (*cmp)())
    }
}
void Bank_Simulatin(int CloseTime)
{
    OpenForBusiness();
    while(!ListEmpty(ev)) {
        DelFirst(GetHead(ev), p); en = GetCurElem(p);
        if(en.NType == 0) CustomerArrived();
        else CustomerDeparture();
    }
    printf("Average Time is %f\n", (float)TotalTime / CustomerNum);
}
