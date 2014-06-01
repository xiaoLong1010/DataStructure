//
//  ArrayList.h
//  basic
//
//  Created by cl on 4/3/14.
//  Copyright (c) 2014 cl. All rights reserved.
//




#ifndef basic_ArrayList_h
#define basic_ArrayList_h

#include <stdbool.h>        //C99新特性

#define LIST_SIZE 100        //数组大小
typedef int DataType;       //定义表元素的数据类型
typedef struct              //线性表的结构体定义
{
	DataType list[LIST_SIZE];
	int length;
}ArrayList;

void initList(ArrayList *L);


bool isEmpty(ArrayList L);


bool getElement(ArrayList L,int index,DataType *element);



int indexOfElement(ArrayList L,DataType element);


bool insert(ArrayList *L,int index,DataType element);


bool delete(ArrayList *L,int index,DataType *element);


int length(ArrayList L);

void clear(ArrayList *L);


#endif
