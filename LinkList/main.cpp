#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#define ElementType int
typedef int Status;
typedef struct LNode{
    ElementType data;
    struct LNode *next;
}*Link,*Position;
typedef struct{
    Link head,tail;
    int length;
}LinkList;
Status MakeNode(Link *P,ElementType e);
void FreeNode(Link &p);
Status InitList(LinkList *L);
Status DestroyList(LinkList *L);
Status ClearList(LinkList *L);
Status InsFirst(Link h,Link s);
Status DelFirst(Link h,Link *q);
Status Append(LinkList *L,Link s);
Status Remove(LinkList *l,Link *q);
Status InsBefore(LinkList *L,Link *p,Link s);
Status InsAfter(LinkList *L,Link *p,Link s);
Status SetCurElem(Link *p,ElementType e);
ElementType GetCurElem(Link *p,ElementType e);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L,Link p);
Position NextPos(LinkList L,Link p);
Status LocatePos(LinkList L,int i,Link *P);
Position LocateElem(LinkList L,ElementType e,Status (* compare)(ElementType,ElementType));
Status ListTraverse(LinkList L,Status (* visit)());
