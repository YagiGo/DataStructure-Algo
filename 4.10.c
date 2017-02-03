#define MaxBookNum 1000
#define MaxKeyNum 2500
#define MaxLineLen 500
#define MaxWordNum 10
typedef struct {
	char *item[];
	int last;
}WordListType;//词表
typedef struct {
	struct LNode *next;
	int data;
}LNode,Linklist;//单链表 存书号索引(int)
typedef struct {
	char *ch;
	int length;
}HString; //堆分配字符串
typedef int Elemtype;//定义链表的数据元素类型为整形
typedef struct {
	HString key;
	Linklist bnolist;
}IdxTermType; //索引项
typedef struct {
	IdxTermType item[MaxKeyNum + 1];
	int last
}IdxListType;//索引表
char *buf; //书目缓冲区
WordListType wdlist; //词表

void InitIdxList(IdxListType &idxlist); //初始化索引表
void GetLine(FILE f);//读取文件的第一行
void ExtractKeyWord(Elemtype &bno);//
void InsIdxList(IdxListType &idxlist, Elemtype bno);//把书号为bno的书名关键词按词典顺序插入索引表idxlist
void PutText(FILE g, IdxListType idxlist);
void GetWord(int i, HString &wd); //把wdlist中第i个关键词存入wd
void Locate(IdxListType idxlist, HString wd, Boolean &b);
//在idxlist中查找是否有与wd相同的关键词，如果存在，返回bno，且使得b=true，反之使b=false
void InsertNewKey(IdxListType &idxlist, int i, HString wd);//插入wd中第i个关键字到idxlist中并且让bnolist初始化为空

void GetWord(WordListType wdlist, int i, HString &wd) 
{
	p = *(wdlist.item + i);
	StrAssign(wd,p);
}
Status InsertBook(IdxListType &idxlist, int i, int bno) 
{
	if(!MakeNode(p, bno)) return ERROR
	append(idxlist.item[i].bnolist, p);
	return OK;
}
void Locate(IdxListType idxlist, HString wd, Boolean &b)
{
	for(i = idxlist.last - 1; (m = StrCompare(idxlist.item[i].key, wd)) > 0; i--);
	if(m == 0) return {b = TRUE; return i;}
	else return b = FALSE;
}
Status InsertNewKey(IdxListType &idxlist, int i, HString wd)
{
	for(j = idxlist.last - 1; j >= i; j--)
	{
		idxlist.item[j + 1] = idxlist.item[j];
	}
	if(!StrCopy(idxlist.item[i].key, wd)) return ERROR;
	if(!InitList(idxlist.item[i].bnolist)) return ERROR;
}
void InsIdxList(WordListType wdlist, IdxListType &idxlist, int bno)
{
	for(i = 0; i < wdlist.last; i++) {
		GetWord(wdlist, i, wd); j = Locate(idxlist, wd, b);
		if(!b) InsertNewKey(idxlist, i, wd); //插入关键字
		if(!InsertBook(idxlist, j, bno)) return OVERFLOW; //插入书号
	}
}
void main()
{
	FILE *f, *g;
	if(!(f = fopen("BookInfo.txt", "r"))) exit(ERROR);
	if(!(g = fopen("BookIdx.txt", "w"))) exit(ERROR);
	while(!feof(f)) 
	{
		GetLine(f);
		ExtractKeyWord(BookNo);
		InsIdxList(wdlist, idxlist, BookNo);
	}
	PutText(g,idxlist);
}
