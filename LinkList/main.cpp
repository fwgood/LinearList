#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
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
typedef struct LNode {
    ElementType data;
    struct LNode *next;
}*Link, *Position;
typedef struct {
    Link head, tail;
    int length;
}LinkList;
Status MakeNode(Link *p, ElementType e);
void FreeNode(Link *p);
Status InitList(LinkList *L);
Status DestroyList(LinkList *L);
Status ClearList(LinkList *L);
Status InsFirst(Link h, Link s);
Status DelFirst(Link h, Link *q);
Status Append(LinkList *L, Link s);
Status Remove(LinkList *l, Link *q);
Status InsBefore(LinkList *L, Link *p, Link s);
Status InsAfter(LinkList *L, Link *p, Link s);
Status SetCurElem(Link *p, ElementType e);
ElementType GetCurElem(Link *p, ElementType e);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L, Link p);
Position NextPos(LinkList L, Link p);
Status LocatePos(LinkList L, int i, Link *P);
Position LocateElem(LinkList L, ElementType e, Status(*compare)(ElementType, ElementType));
Status ListTraverse(LinkList L, Status(*visit)());
int main() {
    printf("123");
}
Status MakeNode(Link *p, ElementType e) {
    (*p) = (Link)malloc(sizeof(LNode)); \
        (*p)->data = e;
    if (!(*p)) {
        return ERROR;
    }
    return OK;
}
void FreeNode(Link *p) {
    free(*p);
}
Status InitList(LinkList *L) {
    L = (LinkList *)malloc(sizeof(LinkList));
    if (!L) {
        return ERROR;
    }
    L->head = NULL;
    L->tail = NULL;
    L->length = 0;
    return OK;
}
Status DestroyList(LinkList *L) {
    Link p, q;
    p = L->head;
    free(L);
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}
Status ClearList(LinkList *L) {
    Link p, q;
    p = L->head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->head = NULL;
    L->tail = NULL;
    L->length = NULL;
    return OK;
}
Status InsFirst(Link h, Link s) {
    s->next = h->next;
    h->next = s;
    return OK;
}
Status DelFirst(Link h, Link *q) {
    (*q) = h->next;
    h->next = h->next->next;
    return OK;
}
Status Append(LinkList *L, Link s) {
    L->tail->next = s;
    while (s->next) {
        s = s->next;
    }
    L->tail = s;
    return OK;
}
