//
//  Queue.h
//  basic
//
//  Created by cl on 4/14/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#ifndef basic_Queue_h
#define basic_Queue_h

#include <stdbool.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node* next;
} LinkQueue,*QueueNode;


typedef struct
{
    QueueNode front;
    QueueNode rear;
}Queue;


bool init(Queue *LQ);       /*将带头结点的链式队列初始化为空队列需要把头结点的指针域置为0*/


bool isEmpty(Queue LQ);     /*判断链式队列是否为空，队列为空返回1，否则返回0*/


bool add(Queue *LQ,DataType data);      /*将元素e插入到链式队列LQ中，插入成功返回1*/


int poll(Queue *Q,DataType *x);     /*出队操作。*/


int GetHead (Queue LQ,DataType *e);     /*取链式队列中的队头元素，并将该元素赋值给e，取元素成功返回1，否则返回0*/




#endif
