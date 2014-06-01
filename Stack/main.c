//
//  main.c
//  Stack
//
//  Created by cl on 4/7/14.
//  Copyright (c) 2014 cl. All rights reserved.
//
/*
 中缀转化成后缀
 1、如果是操作数，直接保存在数组
 2、如果是运算符，当前符号是a2，栈顶符号是a1
    2.1、a2大于a1，a2进栈
    2.1、a2小于a1，a1出栈，再比较
    2.3、如果是左括号，直接进栈；如果是右括号，出栈，直到遇见左括号
 
 */

#include <stdio.h>

#include "Stack.h"

void test1();

int main(int argc, const char * argv[])
{


    middleToPost("9 + (3 - 1) * 2 + 6 / 2");
    
    printf("Hello, World!\n");
    return 0;
}

void test1(){
    Node head;
    init(&head);
    push(&head, 1);
    push(&head, 3);
    push(&head, 6);
    
    pop(&head);
    
    clear(&head);
}

