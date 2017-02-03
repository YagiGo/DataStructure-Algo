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
    ElemType  *base;   /*�����ʵ��*/
    int       dim;     /*����ά��*/
    int       *bounds;/*��������boundӦ����bounds�������ά�ĳ���*/
    int       *constants;
}Array; /*��������зֺ�*/

/*Status InitArray(Array A,int dim,bounds,constants){ �����Ĳ�����������������ͣ�������һ�㶨�巽��������Ӧ���Ǳ�������������Ԫ�ص�ֵ*/
Status InitArray(Array *A,int dim,...){ /*A�����з��أ�������ָ��,dimά��,bounds�constantsδ�õ���Ӧ��ɾ��,...����va_start����ap,Ӧ���Ǹ�ά�ĳ���*/

    int elemtotal=1,i; /*elemtotal,iδ����*/
    va_list ap;/*apҪ����*/
    /*��ά��dim�͸�ά���ȺϷ���������Ӧ������A��������OK */
    if (dim<1||dim>MAX_ARRAY_DIM) return ERROR;
    A->dim=dim;
    A->bounds=(int*)malloc(dim*sizeof(int));
    if(!A->bounds) return ERROR;

    /*����ά���ȺϷ��������A->bounds�������A��Ԫ������elemtotal*/



    va_start(ap,dim);    /* apΪva_list���ͣ��Ǵ�ű䳤��������Ϣ������ */
    for(i=0;i<dim;i++){
        A->bounds[i]=va_arg(ap,int);
        if(A->bounds[i]<0)return UNDERFLOW;
        elemtotal*=A->bounds[i];
       }
    va_end(ap);

    A->base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
    if(!A->base) return ERROR;
    /* ��ӳ�����ĳ���c,������A->constants[i-1],i=1,...dim */
    A->constants=(int*)malloc(dim*sizeof(int));
    if(!A->constants)return ERROR;
    A->constants[dim-1]=1;
    for(i=dim-2;i>=0;--i)
        /*A.constands[i]=A.bounds[i+1]*A.constants[i+1];  constandsӦ����constants*/
        A->constants[i]=A->bounds[i+1]*A->constants[i+1];

     return OK;
}

Status DestroyArray(Array *A){    /*Ҫ�ı�A��������ָ��*/
    /* ��������A */
    /*if(!A->base)return ERROR;����*/
    free(A->base);    /*A.base=NULL;����*/
    /*if(!A->bounds)return ERROR;    ��Ӧ�����������棬����*/
    free(A->bounds);  /*A.bounds=NULL;����*/
    /*if(!A->constants)return ERROR; ��Ӧ���������������*/
    free(A->constants);/*A.constands=NULL;����*/
    return OK;
}

/*Status Locate(Array A,va_list ap,int off){off����ֵ��Ӧ�ô��ݵ�ַ,�������е�offӦ�ø�Ϊ*off*/
Status Locate(Array A,va_list ap,int *off){
    /* ��apָʾ�ĸ��±�־ֵ�Ϸ����������Ԫ����A�����λ�� off */
    int ind,i;/*δ����*/
    /*for(i=0;i<A.dim;  ++i){*/
    *off=0;/*������©*/
    for(i=0;i<A.dim;++i){
        ind=va_arg(ap,int);
        if(ind<0||ind>=A.bounds[i])return ERROR;
        *off+=A.constants[i]*ind;
    }
    return  OK;
}


Status Assign(Array *A,ElemType e,...){ /*Ҫ�ı�A��������ָ�룬����������...*/
    /* A��nά���飬e��Ԫ�ر����������n���±�ֵ */
    /* ���±겻���磬��e��ֵ������ָ����A��Ԫ�أ�������OK */
    va_list ap;/*δ����*/
    Status result;/*δ����*/
    int i,j,k;
    int off;/*δ����*/

    va_start(ap,e);
    if((result=Locate(*A,ap,&off))<0)return result;/*off����ַ,off������0*/
    *(A->base+off)=e;
    va_end(ap);/*����*/
    return OK;
}


Status Value(Array A,ElemType *e,...){ /*eҪ����ֵ����ָ�����������������...,�������{*/
    int off;/*δ����*/
    Status result;/*δ����*/
    va_list ap;/*δ����*/
    va_start(ap,e);
if ((result=Locate(A,ap,&off))<0)return result;  /*Locate���������ı�off������0*/
*e=*(A.base+off);
 va_start(ap,e);

return OK;
}

/*��������֤����*/
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

