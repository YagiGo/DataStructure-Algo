/*  HELLO.C -- Hello, world */
#include<stdarg.h>
#include<stdio.h>
#include<malloc.h>

#include <stdlib.h>

#define OK   1
#define ERROR    0
#define UNDERFLOW
#define MAX_ARRAY_DIM  8
typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType  *base;   /*数组的实体*/
    int       dim;     /*数组维数*/
    int       *bounds;/*根据下文bound应该是bounds，数组各维的长度*/
    int       *constants;
}Array; /*这里必须有分号*/

/*Status InitArray(Array A,int dim,bounds,constants){ 函数的参数必须逐个定义类型，不能用一般定义方法，另外应该是变参数传入数组个元素的值*/
Status InitArray(Array *A,int dim,...){ /*A数组有返回，必须用指针,dim维数,boundsonstants未用到，应该删除,...会由va_start赋给ap,应该是各维的长度*/

    int elemtotal=1,i; /*elemtotal,i未定义*/
    va_list ap;/*ap要定义*/
    /*若维数dim和各维长度合法，则构造相应的数组A，并返回OK */
    if (dim<1||dim>MAX_ARRAY_DIM) return ERROR;
    A->dim=dim;
    A->bounds=(int*)malloc(dim*sizeof(int));
    if(!A->bounds) return ERROR;

    /*若各维长度合法，则存入A->bounds，并求出A的元素总数elemtotal*/



    va_start(ap,dim);    /* ap为va_list类型，是存放变长参数表信息的数组 */
    for(i=0;i<dim;i++){
        A->bounds[i]=va_arg(ap,int);
        if(A->bounds[i]<0)return UNDERFLOW;
        elemtotal*=A->bounds[i];
       }
    va_end(ap);

    A->base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    if(!A->base) return ERROR;
    /* 求映像函数的常数c,并存入A->constants[i-1],i=1,...dim */
    A->constants=(int*)malloc(dim*sizeof(int));
    if(!A->constants)return ERROR;
    A->constants[dim-1]=1;
    for(i=dim-2;i>=0;--i)
        /*A.constands[i]=A.bounds[i+1]*A.constants[i+1];  constands应该是constants*/
        A->constants[i]=A->bounds[i+1]*A->constants[i+1];

     return OK;
}

Status DestroyArray(Array *A){    /*要改变A，必须用指针*/
    /* 销毁数组A */
    /*if(!A->base)return ERROR;多余*/
    free(A->base);    /*A.base=NULL;多余*/
    /*if(!A->bounds)return ERROR;    ！应该在括号里面，多余*/
    free(A->bounds);  /*A.bounds=NULL;多余*/
    /*if(!A->constants)return ERROR; ！应该在括号里面多余*/
    free(A->constants);/*A.constands=NULL;多余*/
    return OK;
}

/*Status Locate(Array A,va_list ap,int off){off返回值，应该传递地址,函数体中的off应该改为*off*/
Status Locate(Array A,va_list ap,int *off){
    /* 若ap指示的各下标志值合法，则求出该元素在A中相对位置 off */
    int ind,i;/*未定义*/
    /*for(i=0;i<A.dim;  ++i){*/
    *off=0;/*不可遗漏*/
    for(i=0;i<A.dim;++i){
        ind=va_arg(ap,int);
        if(ind<0||ind>=A.bounds[i])return ERROR;
        *off+=A.constants[i]*ind;
    }
    return  OK;
}


Status Assign(Array *A,ElemType e,...){ /*要改变A，必须用指针，变参数，后加...*/
    /* A是n维数组，e是元素变量，随后是n个下标值 */
    /* 若下标不超界，则将e的值赋给所指定的A的元素，并返回OK */
    va_list ap;/*未定义*/
    Status result;/*未定义*/
    int i,j,k;
    int off;/*未定义*/

    va_start(ap,e);
    if((result=Locate(*A,ap,&off))<0)return result;/*off传地址,off可以是0*/
    *(A->base+off)=e;
    va_end(ap);/*增加*/
    return OK;
}


Status Value(Array A,ElemType *e,...){ /*e要返回值，用指针变量，变参数，后加...,函数后加{*/
    int off;/*未定义*/
    Status result;/*未定义*/
    va_list ap;/*未定义*/
    va_start(ap,e);
if ((result=Locate(A,ap,&off))<0)return result;  /*Locate函数参数改变off可以是0*/
*e=*(A.base+off);
 va_start(ap,e);

return OK;
}

/*下面是验证部分*/
int main()
{
 int i,j,k;
 Array A;
 ElemType e;
 A.dim=3;

 InitArray(&A,A.dim,2,2,2);

 printf("dim=%d\n",A.dim);
 printf("lenth of every dimension:");
 for (i=0;i<A.dim;i++) printf("%5d",A.bounds[i]);
 printf("\nC constants are:");
 for (i=0;i<A.dim;i++) printf("%5d",A.constants[i]);
 printf("\ninput a char to continue\n");
 getchar();

 printf("Give A random values\n");
 randomize();
 for (i=0;i<A.bounds[0];i++)
   for (j=0;j<A.bounds[1];j++)
      for(k=0;k<A.bounds[2];k++)
        Assign(&A,random(10),i,j,k);

 printf("members of the Array A are:\n");


 for (i=0;i<A.bounds[0];i++)
   {
     for (j=0;j<A.bounds[1];j++)
      { printf("(");
        for (k=0;k<A.bounds[2];k++)
           { Value(A,&e,i,j,k);
           printf("%5d", e);
           }
        printf(")  ");
       }
     printf ("\n");
   }

 printf("Equilent one dim array are:\n");
 for (i=0;i<A.bounds[0]*A.bounds[1]*A.bounds[2];i++) printf("%5d",A.base[i]);
 printf("\n");

 DestroyArray(&A);
 getchar();
 return 0;
 }

