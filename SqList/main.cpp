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
#define elementType int
typedef int Status;
typedef struct{
    elementType *element;
    int length;
    int listSize;
}SqList;
Status InitList_Sq(SqList *L);
Status ListInsert_Sq(SqList *L,int i,elementType e);
Status ListDelete_Sq(SqList *L,int i,elementType *e);
int locateElement(SqList L,elementType e,Status (*compare)(elementType,elementType));
void MergeList_Sq(SqList La,SqList Lb,SqList *Lc);
void DestroyList_Sq(SqList *L);
void ClearList_Sq(SqList *L);
Status ListEmpty_Sq(SqList L);
int ListLength_Sq(SqList L);
Status GetElement(SqList L,int i,elementType *e);
int FindElement_Sq(SqList L,elementType e);
Status PriorElement(SqList L,elementType cur_e,elementType *pre_e);
Status NextElement(SqList L,elementType cur_e,elementType *next_e);
Status ListTraverse(SqList L,Status(*visit)(elementType));
int main(){

}
Status InitList_Sq(SqList *L){
    L->element=(elementType *)malloc(LIST_INIT_SIZE*sizeof(elementType));
    if(!L->element){
        exit(OVERFLOW);
    }
    L->length=0;
    L->listSize=LIST_INIT_SIZE;
    return OK;
}
Status ListInsert_Sq(SqList *L, int i, int e){
    if(i<1||i>L->length+1){
        return ERROR;
    }
    if(L->length>=L->listSize){
        elementType *newBase;
        newBase=(elementType *)realloc(L->element,(L->listSize+LIST_INCREMENT)*sizeof(elementType));
        if(!newBase){
            exit(OVERFLOW);
        }
        L->element=newBase;
        L->listSize+=LIST_INCREMENT;
    }
    elementType *q=&(L->element[i-1]);
    for(elementType *p=&(L->element[L->length-1]);p>=q;p--){
        *(p+1)=*p;
    }
    *q=e;
    ++(L->length);
    return OK;
}
Status ListDelete_Sq(SqList *L, int i, int *e){
    if(i<1||i>L->length){
        return ERROR;
    }
    elementType *p=&(L->element[i-1]);
    *e=*p;
    elementType *q;
    q=L->element+L->length-1;
    for(++p;p<=q;p++){
        *(p-1)=*p;
    }
    --L->length;
    return OK;
}
int locateElement(SqList *L, int e, Status (*compare)(int, int)){
    int i=1;
    elementType *p;
    p=L->element;
    while (i<=L->length&&!(*compare)(*p++,e)) {
        ++i;
    }
    if(i<L->length){
        return i;
    }else{
        return 0;
    }
}
void MergeList_Sq(SqList La, SqList Lb, SqList *Lc){
    elementType *pa=La.element,*pb=Lb.element;
    Lc->length=La.length+Lb.length;
    Lc->listSize=Lc->length;
    Lc->element=(elementType *)malloc(Lc->listSize*sizeof(elementType));
    elementType *pc=Lc->element;
    if(!Lc->element){
        exit(OVERFLOW);
    }
    elementType *pa_last,*pb_last;
    pa_last=La.element+La.length-1;
    pb_last=Lb.element+Lb.length-1;
    while(pa<pa_last&&pb<=pb_last){
        if(pa<=pb){
            *pc++=*pa++;
        }else{
            *pc++=*pc++;
        }
    }
    while (pa<=pa_last) {
        *pc++=*pa++;
    }
    while (pb<=pa_last) {
        *pc++=*pb++;
    }
}
void DestroyList_Sq(SqList *L){
    if(L->element){
        free(L->element);
        L->element=NULL;
        L->length=0;
        L->listSize=0;
    }
}
void ClearList_Sq(SqList *L){
    L->length=0;
}
Status ListEmpty_Sq(SqList L){
    if(L.length=0){
        return TRUE;
    }else{
        return FALSE;
    }
}
int ListLength_Sq(SqList L){
    return L.length;
}
Status GetElement(SqList L, int i, elementType *e){
    if(i<1||i>ListLength_Sq(L)){
        return ERROR;
    }
    *e=L.element[i-10];
    return OK;

}
int FindElement_Sq(SqList L, int e){
    int i=1;
    elementType *p;
    p=L.element;
    while(i<L.length&&*p++!=e){
        ++i;
    }
    if(i<L.length){
        return i;
    }else{
        return 0;
    }
}
Status PriorElement(SqList L, elementType cur_e, elementType *pre_e){
    int cur_e_p=FindElement_Sq(L,cur_e);
    if(cur_e_p<=1||cur_e_p>L.length){
        return ERROR;
    }
    *pre_e=L.element[cur_e_p-2];
    return OK;

}
Status NextElement(SqList L, elementType cur_e, elementType *next_e){
    int cur_e_p=FindElement_Sq(L,cur_e);
    if(cur_e_p>=L.length||cur_e_p<=0){
        return ERROR;
    }
    *next_e=L.element[cur_e_p];
    return OK;

}
Status ListTraverse(SqList L, Status (*visit)(elementType)){
    int i=0;
    while((*visit)(L.element[i])){
        i++;
    }
    if(i<L.length){
        return ERROR;
    }else {
        return OK;
    }
}
