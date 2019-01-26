#include <stdio.h>
#include <stdlib.h>
#include "TestSqList.h"
int main() {
    int opt;
    Ptr list=NULL;
    int pos,size,i;
    ElemType e,*data;
    Status s;
    while(1){
        printf("请输入选项:\n");
        printf("1.测试建立线性表\n");
        printf("2.测试清空线性表\n");
        printf("3.测试求某位置的线性表的线性表元素及前驱后继\n");
        printf("4.测试线性表的某元素的位置\n");
        printf("5.测试线性表的长度\n");
        printf("6.结束程序\n");
        scanf("%d", &opt);
        freopen("test.txt", "r", stdin);
        switch (opt){
            case 1:
                printf("线性表的长度:\n");
                scanf("%d",&size);
                data=(ElemType*)malloc(size* sizeof(ElemType));
                printf("线性表元素:\n");
                for(i=0;i<size;i++){
                    scanf("%d",&data[i]);
                }
                s=Test_CreateList(&list,data,size);
                if(s!=success){
                    printf("建立线性表失败\n");
                }
                free(data);
                List_Destory(&list);
                break;
            case 2:
                printf("线性表的长度:\n");
                scanf("%d",&size);
                data=(ElemType*)malloc(size* sizeof(ElemType));
                printf("线性表元素:\n");
                for(i=0;i<size;i++){
                    scanf("%d",&data[i]);
                }
                s=Test_CreateList(&list,data,size);
                if(s==success){
                   /*if(!List_Empty(list)){
                       List_Clear(list);
                       if(List_Empty(list)){
                           printf("清空线性表成功\n");
                       }
                   }*/
                   s=Test_ClearList(&list);
                   if(s==success){
                       printf("清空线性表成功\n");
                   }
                }
                free(data);
                List_Destory(&list);
                break;
            case 3:
                printf("线性表的长度:\n");
                scanf("%d",&size);
                data=(ElemType*)malloc(size* sizeof(ElemType));
                printf("线性表元素:\n");
                for(i=0;i<size;i++){
                    scanf("%d",&data[i]);
                }
                s=Test_CreateList(&list,data,size);
                if(s==success){
                    printf("请输入查找的位置:\n");
                    scanf("%d",pos);
                    Test_RetrivalPriorNext(list,pos);
                }
                free(data);
                List_Destory(&list);
                break;
            case 4:
                printf("线性表的长度:\n");
                scanf("%d",&size);
                data=(ElemType*)malloc(size* sizeof(ElemType));
                printf("线性表元素:\n");
                for(i=0;i<size;i++){
                    scanf("%d",&data[i]);
                }
                s=Test_CreateList(list,data,size);
                if(s==success){
                    printf("输入待查询的元素值:\n");
                    scanf("%d",&e);
                    Test_Locate(list,e);
                }
                free(data);
                List_Destory(&list);
                break;
            case 5:
                printf("线性表的长度:\n");
                scanf("%d",&size);
                data=(ElemType*)malloc(size* sizeof(ElemType));
                printf("线性表元素:\n");
                for(i=0;i<size;i++){
                    scanf("%d",&data[i]);
                }
                s=Test_CreateList(list,data,size);
                if(s==success){
                    Test_Size(list);
                }
                free(data);
                List_Destory(&list);
                break;
            case 6:
                break;
            default:
                break;
        }
    }
    return 0;
}