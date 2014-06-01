//
//  LinkList.h
//  basic
//
//  Created by cl on 4/5/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#ifndef basic_LinkList_h
#define basic_LinkList_h

#include <stdbool.h>        //C99新特性

typedef int DataType;       //定义表元素的数据类型
typedef struct node              //单链表的结构体定义
{
	DataType data;
	struct node *next;
} Node,*LinkList;

bool init(LinkList *head);     //链表初始化

bool insertAfterIndex(LinkList head,int index,DataType data);     //通过索引插入数据

bool insertAfterNode(Node *node,DataType data);



//
//bool isEmpty(LinkList L);
//
//
//bool getElement(LinkList L,int index,DataType *element);
//
//
//
//int indexOfElement(LinkList L,DataType element);
//
//
//bool insert(LinkList *L,int index,DataType element);
//
//
//bool delete(LinkList *L,int index,DataType *element);
//
//
//int length(LinkList L);

bool dealloc(LinkList *L);



#endif
