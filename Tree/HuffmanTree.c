//
//  HuffmanTree.c
//  basic
//
//  Created by cl on 4/17/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "HuffmanTree.h"

void createH(HuffmanTree **HT,char datas[],int weights[],int n){
    
    //先创建最小的两个权值结点
    HuffmanTree *tmp1 = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    tmp1->data = datas[0];
    tmp1->weight = weights[0];
    tmp1->lchild = NULL;
    tmp1->rchild = NULL;
    
    HuffmanTree *tmp2 = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    tmp2->data = datas[1];
    tmp2->weight = weights[1];
    tmp2->lchild = NULL;
    tmp2->rchild = NULL;
    
    //最小两个权值结点的父结点
    HuffmanTree *tmp = (HuffmanTree *)malloc(sizeof(HuffmanTree));
    tmp->data = '1';
    tmp->weight = weights[0] + weights[1];
    tmp->lchild = tmp1;
    tmp->rchild = tmp2;
    
    for (int i = 2; i < n; i++) {
        HuffmanTree *son = (HuffmanTree *)malloc(sizeof(HuffmanTree));
        son->data = datas[i];
        son->weight = weights[i];
        son->lchild = NULL;
        son->rchild = NULL;

        HuffmanTree *parent = (HuffmanTree *)malloc(sizeof(HuffmanTree));
        parent->data = '1';
        parent->weight = tmp->weight + son->weight;
        parent->lchild = son;
        parent->rchild = tmp;
        
        tmp = parent;
        
    }
    
    *HT = tmp;

}

//先序遍历
void preOrderTraverseH(HuffmanTree *T){
    
//    static int count;
    
    if (T) {
        
        printf("%c\n",T->data);
//        count++;
//        printf("%d\n",count);
        preOrderTraverseH(T->lchild);
        preOrderTraverseH(T->rchild);
    }
    
    
}

//后序销毁二叉树
void destroyH(HuffmanNode *T){
    
    if (*T) {
        if ((*T)->lchild) {
            destroyH( &((*T)->lchild) );
        }
        if ((*T)->rchild) {
            destroyH( &((*T)->rchild) );
        }
        printf("remove node %c\n",(*T)->data);
        free(*T);
        *T = NULL;
    }
}

