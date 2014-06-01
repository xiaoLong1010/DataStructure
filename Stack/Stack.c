//
//  Stack.c
//  basic
//
//  Created by cl on 4/7/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Stack.h"

#define  NUM 32


void init(Node *top)
{
    *top = NULL;
}

bool isEmpty(Stack *top)
{
    return top ? false : true;
}

bool push(Node *top,DataType data)
{
//    if (!(*top)) {
//        printf("the top is null!\n");
//        return  false;
//    }
    
    Node node = (Node)malloc(sizeof(Stack));
    
    if ( !node)  {
        printf("faile to alloc node!\n ");
        return false;
    }
    else
    {
        node->data = data;
        node->next = *top;
        *top = node;
        return true;
    }

    return false;
}

DataType pop(Node *top)
{
    if (!(*top)) {
        printf("the top is null!\n");
        return  false;
    }
    
    Node node = *top;
    *top = (*top)->next;    //栈顶下移
    
    DataType data = node->data;     //取出数据 
    free(node);     //释放结点
    
    return data;     //
}

bool clear(Node *top)
{
    while (*top) {
        Node temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    
    if (!(*top)) {
        return true;
    }
    
    return false;
    
    
}

void middleToPost(const char *expression)
{
    //1、初始化栈
    Node top;
    init(&top);
    
    const char *p = expression;
    char postExps[NUM];
    int index = 0;
    
    while (*p) {
        if( ((*p) >= '0') && ((*p) <= '9') ){       //如果是数字
            postExps[index++] = *p;
            //p++;
        }
        else if (((*p) == '*') || ((*p) == '/')){               //如果当前符号是乘号，除号
            while ( !isEmpty(top) && ((top->data == '*') || (top->data == '/')) ) {     //栈非空，栈顶是乘号，除号，则出栈
                    postExps[index++] = pop(&top);
                
            }
            push(&top, *p);                         //当前符号入栈
        }
        else if (((*p) == '+') || ((*p) == '-')){               //如果当前符号是加号，减号
            while ( !isEmpty(top) && (top->data != '(') ) {    //栈非空，栈顶不是(，则出栈
                    postExps[index++] = pop(&top);
            }
            push(&top, *p);                         //当前符号入栈
        }
        else if ((*p) == '('){
            push(&top, *p);      //当前符号入栈
        }
        else if ((*p) == ')'){
            while ( !isEmpty(top) && (top->data != '(') ) {    //栈非空，栈顶不是(，则出栈
                postExps[index++] = pop(&top);
            }
            if (isEmpty(top)) {
                printf("数据错误");
                return;
            }
            pop(&top);      // '('出栈
        
        }
        else if((*p) == ' '){  //如果是空格则什么都不做

        }
        else{
            printf("未知符号");
            return;
        }
        p++;
    }
    
    while (!isEmpty(top)) {         //將栈中所有的数据出栈
        postExps[index++] = pop(&top);
    }
    clear(&top);
    
    postExps[index] = '\0';
    printf("后缀表达式：%s\n",postExps);

}


