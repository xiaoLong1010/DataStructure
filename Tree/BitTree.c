//
//  BitTree.c
//  basic
//
//  Created by cl on 4/13/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BitTree.h"

#define SIZE 32

void init(BitNode *T){
    *T = NULL;
}


//先序创建二叉树
void create(BitNode *T){
    
    
    DataType ch;
    
    scanf("%c",&ch);
    
    if (ch == '#') {
        *T = NULL;
    
    }else{
        
        *T = (BitNode)malloc(sizeof(BitTree));
        if (!(*T)) {
            printf("malloc node failed");
            return;
        }
        (*T)->data = ch;
        
        create( &((*T)->lchild) );
        create( &((*T)->rchild) );
    }
    
}

//后序销毁二叉树
void destroy(BitNode *T){

    if (*T) {
        if ((*T)->lchild) {
            destroy( &((*T)->lchild) );
        }
        if ((*T)->rchild) {
            destroy( &((*T)->rchild) );
        }
        printf("remove node %c\n",(*T)->data);
        free(*T);
        *T = NULL;
    }
}

//先序遍历
void preOrderTraverse(BitTree *T){
    
    static int count;
    
    if (T) {
        
        printf("%c\n",T->data);
        count++;
        printf("%d\n",count);
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }

    
}

//先序遍历
void preOrderTraverseAndCount(BitTree *T,int *count){
    
    static int tmp;
    
    if (T) {
        
        printf("%c\n",T->data);
        tmp++;
        *count = tmp;
        
        preOrderTraverseAndCount(T->lchild, count);
        preOrderTraverseAndCount(T->rchild, count);
    }
    
    
}

//中序遍历
void inOrderTraverse(BitTree *T){
    
    if (T) {        
        preOrderTraverse(T->lchild);
        printf("%c\n",T->data);
        preOrderTraverse(T->rchild);
    }    
    
}

//后序遍历
void postOrderTraverse(BitTree *T){
    
    if (T) {
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
        printf("%c\n",T->data);
    }
    
}

//按层次遍历
void printLevel(BitTree *T){
    
    if (!T) {
        printf("二叉树不能为空");
        return;
    }
    
    BitTree *queue[SIZE];       //用数组创建队列
    int front,rear;
    front = rear = 0;
    
    queue[rear++] = T;     //头结点进队列
    
    while (rear != front) {     //队列不为空
        BitNode temp = queue[front];    //出队列
        front = (front + 1) % SIZE;
        
        printf("%c",temp->data);
        
        if (temp->lchild) {     //左结点不为空
            if ((rear + 1) != front) {      //队列没有满
                queue[rear] = temp->lchild;
                rear = (rear + 1) % SIZE;
            }else{
                printf("队列已满");
                return;
            }
        }
    
        if (temp->rchild) {     //右结点不为空
            if ((rear + 1) != front) {      //队列没有满
                queue[rear] = temp->rchild;
                rear = (rear + 1) % SIZE;
            }else{
                printf("队列已满");
                return;
            }
        }
        
    }
    
    printf("\n");
    
}

//按照树状输出
void printTree(BitTree *T,int level){
    if (!T) {
        printf("二叉树不能为空");
        return;
    }
    
    if (T->rchild) {        //打印右结点
        printTree(T->rchild, level + 1);
    }
    
    for (int i = 1; i < level; i++) {       //打印中心结点
        printf("    ");
    }
    printf("%c\n",T->data);

    if (T->lchild) {        //打印左结点
        printTree(T->lchild, level + 1);
    }
    
}

//计算叶子结点数
int getLeafNum(BitTree *T){
    if (!T) {
        return 0;   
    }
    else if ( !(T->lchild) && !(T->rchild)) {       //叶子结点
        return 1;
    }
    else{
        return getLeafNum(T->lchild) + getLeafNum(T->rchild);
    }
}

//计算非叶子结点数
int getNotLeafNum(BitTree *T){
    if (!T) {
        return 0;
    }
    else if ( !(T->lchild) && !(T->rchild)) {       //叶子结点
        return 0;
    }
    else{
        return getNotLeafNum(T->lchild) + getNotLeafNum(T->rchild) + 1;
    }
}

//计算深度
int getDepth(BitTree *T){
    if (!T) {
        return 0;
    }
    
    return getDepth(T->lchild) > getDepth(T->rchild) ? (getDepth(T->lchild) + 1) : (getDepth(T->rchild) + 1);
}

