//
//  Stack.h
//  basic
//
//  Created by cl on 4/7/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#ifndef basic_Stack_h
#define basic_Stack_h

#include <stdbool.h>

typedef char DataType;

typedef struct stack{
    DataType data;
    struct stack *next;
} Stack,*Node;

void init(Node *head);     //初始化

bool push(Node *head,DataType data);

DataType pop(Node *head);

bool clear(Node *top);

void middleToPost(const char *expression);
#endif
