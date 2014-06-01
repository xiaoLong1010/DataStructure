//
//  BitTree.h
//  basic
//
//  Created by cl on 4/13/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#ifndef basic_BitTree_h
#define basic_BitTree_h

typedef char DataType;

typedef struct Node				/*二叉链表存储结构类型定义*/
{
	DataType data;			 	/*数据域*/
	struct Node *lchild; 			/*指向左孩子结点*/
	struct Node *rchild; 			/*指向右孩子结点*/
} BitTree,*BitNode;


void init(BitNode *T);

void destroy(BitNode *T);

void create(BitNode *T);

int insertLeftChild(BitNode p,BitNode c);

int insertRightChild(BitNode p,BitNode c);

BitNode point(BitNode T,DataType e);

DataType getLeftChild(BitNode T,DataType e);

DataType getRightChild(BitNode T,DataType e);

int deleteLeftChild(BitNode p);

int deleteRightChild(BitNode p);

void preOrderTraverse(BitTree *T);

void inOrderTraverse(BitTree *T);

void postOrderTraverse(BitTree *T);

void printLevel(BitTree *T);

void printTree(BitTree *T,int level);

void preOrderTraverseAndCount(BitTree *T,int *count);

int getLeafNum(BitTree *T);

int getNotLeafNum(BitTree *T);

int getDepth(BitTree *T);

#endif
