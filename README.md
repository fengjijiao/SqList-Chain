# SqList-Chain

## Base function

`Status List_Init(SqListPtr L);`

`void List_Destory (SqListPtr L);`

`void List_Clear(SqListPtr L);`

`bool List_Empty (SqListPtr L);`

`int List_Size (SqListPtr L);`

`Status List_Retrival(SqListPtr L, int pos, ElemType *elem);`

`Status List_Find(SqListPtr L,int pos,Ptr *pAddr);`

`Status List_Locate(SqListPtr L, ElemType elem, int *pos);`

`Status List_Insert(SqListPtr L, int pos, ElemType elem);`

`Status List_delete(SqListPtr L, int pos);`

`Status List_Prior (SqListPtr L, int pos, ElemType *elem);`

`Status List_Next(SqListPtr L, int pos, ElemType *elem);`

## Basic functions defined by the test

`void List_Print(SqListPtr L);`

## Test function

`Status Test_CreateList(SqListPtr list,ElemType data[],int n);`

`Status Test_ClearList(SqListPtr list);`

`Status Test_RetrivalPriorNext(SqListPtr list,int pos);`

`Status Test_Locate(SqListPtr list,ElemType e);`

`void Test_Size(SqListPtr list);`
