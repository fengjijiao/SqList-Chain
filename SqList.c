//
// Created by fengj on 2019/1/26.
//
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

//基本函数
Status List_Init(SqListPtr L){
    Status s=fail;
    Ptr p;
    if(*L==NULL){
        p=(Ptr)malloc(sizeof(Node));
        if(p==NULL) {
            return s;
        }else{
            *L=p;
            (*L)->next=NULL;
            s=success;
        }
    }
    return s;
}
void List_Destory(SqListPtr L){
//    Ptr p;
/*    if(*L){
        p=(*L)->next;
        while (p){
            (*L)->next=p->next;
            free(p);
            p=(*L)->next;
            //L->1->2->3  ==> L->2->3 && free(2)
        }
        free(*L);
        *L=NULL;
    }
*/
    List_Clear(L);
    if(*L){
        free(*L);
        *L=NULL;
    }
}
void List_Clear(SqListPtr L){
    Ptr p;
    if(*L){
        p=(*L)->next;
        while (p){
            (*L)->next=p->next;
            free(p);
            p=(*L)->next;
            //L->1->2->3  ==> L->2->3 && free(2)
        }
    }
}
bool List_Empty(SqListPtr L){
    return ((*L)->next==NULL);
}
int List_Size(SqListPtr L){
    int len=0;
    Ptr p=(*L)->next;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
Status List_Retrival(SqListPtr L, int pos, ElemType *elem){
    Status s=rang_error;
    Ptr p=(*L)->next;
    int i=1;
    while(p && i<pos){
        ++i;
        p=p->next;
    }
    if(p && i==pos){
        *elem=p->elem;
        s=success;
    }
    return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *pos){
    Status s=fail;
    Ptr p=(*L)->next;
    int i=1;
    while(p){
        if(p->elem == elem){
            s=success;
            *pos = i;
            break;
        }
        ++i;
        p=p->next;
    }
    return s;
}
Status List_Find(SqListPtr L,int pos,Ptr *pAddr){
    int i=1;
    Status s=fail;
    Ptr p=(*L)->next,q=(*L);
    while(i<pos && p){
        q=p;
        p=p->next;
        ++i;
    }
    if(i==pos){
        *pAddr=p;
        s=success;
    }
    return s;
}
Status List_Insert(SqListPtr L, int pos, ElemType elem){
    int i=1;
    Status s=fail;
    Ptr p,q=NULL;
    /*Ptr p=(*L)->next,q=(*L);
    while(i<pos && p){//
        q=p;
        p=p->next;
        ++i;
    }*/
    if(pos>1) {
        s = List_Find(L, pos - 1, &q);
        if (s == success) {
            p = (Ptr) malloc(sizeof(Node));
            if (p) {
                p->elem = elem;
                p->next = q->next;
                q->next = p;
                s = success;
            }
        }
    }else{//在第一个位置插入直接插入头节点后
        p = (Ptr) malloc(sizeof(Node));
        if (p) {
            p->elem = elem;
            p->next = (*L)->next;
            (*L)->next = p;
            s = success;
        }
    }
    return s;
}
Status List_delete(SqListPtr L, int pos){
    Status s=fail;
    Ptr p, q=NULL;
    int i=1;
    /*Ptr p=(*L)->next,q=(*L);
    while(i<pos && p){
        ++i;
        q=p;
        p=p->next;
    }*/
    s=List_Find(L,pos-1,&q);
    if(s==success){
        p=q->next;
        if(p!=NULL){
            q->next=p->next;
            free(p);
            p=NULL;
            s=success;
        }
    }
    return s;
}
Status List_Prior(SqListPtr L, int pos, ElemType *elem){
    Status s;
    Ptr q=NULL;
    s=List_Find(L,pos-1,&q);
    if(s==success){
        *elem=q->elem;
        s=success;
    }
    return s;
}
Status List_Next(SqListPtr L, int pos, ElemType *elem){
    Status s;
    Ptr q=NULL;
    s=List_Find(L,pos,&q);
    if(s==success){
        if(q->next != NULL){
            *elem=q->next->elem;
            s=success;
        }else{
            s=fail;
        }
    }
    return s;
}
//由测试需要所定义的基本函数
void List_Print(SqListPtr L){
    Ptr p=(*L)->next;
    int i=1;
    while(p){
        printf("%d ",p->elem);
        if(i++%10==0){
            printf("\n");
        }
    }
}

