//
// Created by fengj on 2019/1/26.
//
#pragma once
#define bool int

typedef enum Status{
    success,fail,fatal,rang_error
} Status;
typedef int ElemType;
typedef struct Node{
    ElemType *elem;
    struct Node *next;
}Node,*Ptr;
typedef Ptr *SqListPtr;//头节点的指向问题
//基本函数
Status List_Init(SqListPtr L);
void List_Destory (SqListPtr L);
void List_Clear(SqListPtr L);
bool List_Empty (SqListPtr L);
int List_Size (SqListPtr L);
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);
Status List_Locate(SqListPtr L, ElemType elem, int *pos);
Status List_Find(SqListPtr L,int pos,Ptr *pAddr);
Status List_Insert(SqListPtr L, int pos, ElemType elem);
Status List_delete(SqListPtr L, int pos);
Status List_Prior (SqListPtr L, int pos, ElemType *elem);
Status List_Next(SqListPtr L, int pos, ElemType *elem);
//由测试需要所定义的基本函数
void List_Print(SqListPtr L);
