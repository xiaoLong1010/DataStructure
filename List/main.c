//
//  main.c
//  List
//
//  Created by cl on 4/3/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

/*
 1、用指针之前一定进行空指针判断
 */
#include <stdio.h>
#include <stdbool.h>

#include "ArrayList.h"
#include "LinkList.h"

#define  N 16

void arrayListTest();



int main(int argc, const char * argv[])
{

    LinkList head;
    
    init(&head);
    
    insertAfterIndex(head, 0, 2);
    
    if(dealloc(&head)) printf("dealloc \n");
    
    return 0;
}


void arrayListTest()
{
    ArrayList list;
    DataType element = 2;
    
    //初始化
    initList(&list);
    
    for (int i = 0; i < N; i++)
    {
        insert(&list, i, i);
    }
    printf("线性表长度 = %d\n",length(list));
    
    DataType *data = &element;
    int index = 18;
    getElement(list, index, data);
    printf("获取索引%d的元素%d\n",index,*data);
    
    
    delete(NULL, 19, data);
    printf("线性表长度 = %d\n",length(list));
}

