//
//  Queue.c
//  basic
//
//  Created by cl on 4/14/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"


bool init(Queue *LQ){

    LQ->front = LQ->rear = (LinkQueue *)malloc(sizeof(LinkQueue));
    
    if (!(LQ->front)) {
        printf("alloc node failed");
        return false;
    }
    LQ->front->next = NULL;
    return true;

}

bool add(Queue *LQ,DataType data){
    if (!LQ)
    {
        printf("the queue is null!\n");
        return  false;
    }
    
    QueueNode temp = (QueueNode)malloc(sizeof(LinkQueue));
    if (!temp) {
        printf("alloc node failed");
        return false;
    }
    
    temp->data = data;    
    temp->next = NULL;
    
    LQ->rear->next = temp;    
    LQ->rear = temp;
    
    return true;
    
}

 
