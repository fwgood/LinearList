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
#define elementType int
typedef int Status;
typedef struct LNode{
    elementType data;
    struct LNode *next;
}*Link,*Position;
typedef struct{
    Link head,tail;
    int length;
}LinkList;
