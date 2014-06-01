//
//  LinkList.c
//  basic
//
//  Created by cl on 4/5/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

//#include <stdio.h>
//int printf()
//{
//    return 1;
//}
#include <stdio.h>
#include <stdlib.h>

#include "LinkList.h"

bool init(LinkList *head)
{
    if( (*head = (LinkList)malloc(sizeof(Node))) )  //分配存储空间成功
    {
        (*head)->next = NULL;       //下一个节点为空
        return  true;
    }
    return false;
}

bool insertAfterIndex(LinkList head,int index,DataType data)
{
    if (!head)
    {
        printf("the head is null!\n");
        return  false;
    }
    else if (index < 0)
    {
        printf("the index is below zero!\n");
        return  false;
    }
    
    LinkList link = head;
    
    while ((link->next) && (index > 0)) {       //依次查找，
        link = link->next;
        index--;
    }
    if(index > 0)
    {
        printf("index is over the length of linklist!\n");
        return false;
    }
    
    return insertAfterNode(link, data);    

//    LinkList temp = (LinkList)malloc(sizeof(Node));             //创建节点
//    temp->data = data;
//    
//    if (link->next) {                  //如果不是插在最后一个节点之后                 
//        temp->next = link->next;       //插入节点
//        link->next = temp;
//        return true;
//    }
//    else
//    {
//        link->next = temp;
//        temp->next = NULL;
//        return true;
//    }
//   
//    return false;
    

}


bool insertAfterNode(Node *node,DataType data)
{
    
    if (!node)
    {
        printf("the node is null!\n");
        return  false;
    }
    //创建节点
    LinkList temp = (LinkList)malloc(sizeof(Node));
    if(!temp)           //分配结点失败
    {
        printf("faile to alloc node!\n ");
        return false;
    }
    else
    {
        temp->data = data;
    
        temp->next = node->next;
        node->next = temp;
        
        return true;
    }

    return  false;
//    if (node->next) {                  //如果不是插在最后一个节点之后
//        temp->next = node->next;       //插入节点
//        node->next = temp;
//        return true;
//    }
//    else
//    {
//        node->next = temp;
//        temp->next = NULL;
//        return true;
//    }
    

}


bool dealloc(LinkList *head)
{
    if (!(*head))       //头结点为空
    {
        printf("the head is null!\n");
        return  false;
    }
    
    LinkList link = (*head)->next;
    free((*head));          //释放头结点空间
    *head = NULL;           //將头结点置为NULL
    
    while (link)
    {
        LinkList temp = link;
        free(link);
        link = temp->next;
    }
    
    return  true;
}


