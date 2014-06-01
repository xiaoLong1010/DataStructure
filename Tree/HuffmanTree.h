//
//  HuffmanTree.h
//  basic
//
//  Created by cl on 4/17/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#ifndef basic_HuffmanTree_h
#define basic_HuffmanTree_h

typedef char DataType;

typedef struct Node				/*HuffmanTree链表存储结构类型定义*/
{
	DataType data;			 	/*数据域*/
    int weight;
	struct Node *lchild; 			/*指向左孩子结点*/
	struct Node *rchild; 			/*指向右孩子结点*/
} HuffmanTree,*HuffmanNode;

void createH(HuffmanTree **HT,char datas[],int weights[],int n );

void preOrderTraverseH(HuffmanTree *HT);

void destroyH(HuffmanNode *HT);

#endif
