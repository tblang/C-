#include <stdio.h>
#include <stdlib.h>
#define INIT_LIST_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

//构造空的线性表
Status InitList(SqList *L)
{
    L->elem = (ElemType *)malloc(INIT_LIST_SIZE * sizeof(ElemType));
    if(!L->elem)
    {
        exit (OVERFLOW);
    }
    L->length = 0;
    L->listsize = INIT_LIST_SIZE;
    return OK;
}

//从表中得到元素
Status GetElem(SqList L,int i,ElemType *e)
{
    *e = L.elem[i-1];
    return *e;
}

//定位有无元素在表中
Status LocateElem(SqList L,ElemType e)
{
    for(int i = 0;i<L.length;i++)
    {
        if(L.elem[i] == e)
            return 1;
    }
    return 0;
}

//线性表的插入
Status InsertList(SqList *L,int i,ElemType e)
{
    if(L->length == L->listsize)
    {
        ElemType *newbase;
        newbase = (ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    if(i<0||i>L->length+1)
    {
        printf("插入位置错误");
        return ERROR;
    }
    else
    {
        for(int j=L->length;j>i-1;j--)
        {
            L->elem[j]=L->elem[j-1];
        }
        L->elem[i-1] = e;
    }
    ++L->length;
    return 0;
}

//无序表的合并
Status UnionList(SqList *La,SqList Lb,ElemType *e)
{
    int La_len,Lb_len;
    La_len=La->length;
    Lb_len=Lb.length;
    for(int i = Lb_len; i>0; i--)
    {
        GetElem(Lb,i,e);
        if(!LocateElem(*La,*e))
        {
            InsertList(La,++La_len,*e);
        }
    }
    return 0;
}

//线性表动态赋值
/*Status ListInput(SqList *L)
{
    int a;
    printf("请给线性表赋值，输入-1结束:\n");
    for(int i=0;i<L->listsize;i++)
    {
        scanf("d%,",&a);
        if(a==-1)
        {
            break;
        }
        else
        {
            L->elem[i]=a;
            L->length++;
        }
    }
}*/

//线性表动态赋值重写
Status ListInput2(SqList *L)
{
    int a,dex=0;
    printf("输入到-1结束：\n");
    while(1)
    {
        scanf("%d ",&a);
        if(a == -1)  break;
        L->elem[dex++]=a;
        L->length++;
    }
	return 0;
}

//求线性表的长度
/*Status ListLength(SqList L)
{
    if(L.elem)
    {
        return L.length;
    }
    puts("表不存在，无法求长度！");
    return 0;
}*/

//遍历线性表
/*Status TraverseList(SqList L)
{
    printf("线性表的序列为：\n");
    for(int i = 0; i<L.length; i++)
    {
        printf("d% ",L.elem[i]);
    }
    return 0;
}*/

//遍历线性表2
Status TraverseList2(SqList L,int x,int index)
{
    printf("线性表的序列为:\n");
    while(1)
    {
        x = L.elem[index++];
        printf("%d ",x);
        if(index>=L.length)
        {
            break;
        }
    }
	return 0;
}
int main()
{
    SqList La,Lb;
    ElemType e;
    int x,index=0;
    InitList(&La);
    int lb[]={1,2,3,4,5,6,7};
    InitList(&Lb);     //两个线性表初始化
    ListInput2(&La);
    Lb.elem = lb;
    Lb.length = 7;
    TraverseList2(La,x,index);
//    ListInput2(&Lb);    //给两个线性表赋值
    TraverseList2(Lb,x,index);  //遍历两个线性表
    UnionList(&La,Lb,&e);
    TraverseList2(La,x,index);
}

