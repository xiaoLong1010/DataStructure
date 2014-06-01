//
//  ArrayList.c
//  basic
//
//  Created by cl on 4/3/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

/*
 1、用指针之前一定进行空指针判断
 */

#include <stdio.h>
#include "ArrayList.h"

void initList(ArrayList *L)
/*将线性表初始化为空的线性表只需要把线性表的长度length置为0*/
{
	if (!L) {               //判断空指针 
        printf("空指针\n");
        return;
    }

    L->length = 0;	/*把线性表的长度置为0*/
}

bool isEmpty(ArrayList L)
/*判断线性表是否为空，线性表为空返回1，否则返回0*/
{
    if(L.length == 0)			/*判断线性表的长度是否为9*/
        return true;			/*当线性表为空时，返回1；否则返回0*/
    else
        return false;
}

bool getElement(ArrayList L,int index,DataType *element)
/*查找线性表中第i个元素。查找成功将该值返回给e，并返回1表示成功；否则返回-1表示失败。*/
{
	/*判断线性表是否为空*/    
    if (0 == L.length) {
        printf("线性表为空\n");
        return false;
    }
    
    /*判断索引值是否合理*/
    if(index < 0)  	
    {
        printf("索引值小于0\n");
        return false;
    }
    else if (index > L.length - 1)
    {
        printf("索引值大于线性表长度\n");
        return false;
    }
    
    if (element) {                         //非空指针
        *element = L.list[index];			/*将第i个元素的值赋值给e*/
    }

    
    return true;
}


int indexOfElement(ArrayList L,DataType element)
/*查找线性表中元素值为e的元素，查找成功将对应元素的序号返回，否则返回0表示失败。*/
{
	/*判断线性表是否为空*/
    if (0 == L.length) {
        printf("线性表为空\n");
        return -1;
    }

	for(int i = 0;i < L.length;i++)     /*遍历数组查找*/
    {
        if(L.list[i] ==element)
        {
			return i;        
        }

    }

    return -1;
}


bool insert(ArrayList *L,int index,DataType element)
/*在顺序表的第i个位置插入元素e，插入成功返回1，如果插入位置不合法返回-1，顺序表满返回0*/
{
    
	if (!L)                                 //空指针判断
    {
        printf("空指针\n");
        return false;
    }
    else if((index < 0) || (index > L->length ))				/*判断插入位置是否合法*/
	{
        printf("插入位置不合法！\n");
        return false;
	}
	else if(L->length >= LIST_SIZE)		/*在插入元素前，判断顺序表是否已经满，不能插入元素*/
	{
		printf("顺序表已满，不能插入元素。\n");
		return false;
	}
    
    for(int i = L->length - 1;i >= index;i--)			/*将第index个位置以后的元素依次后移*/
    {
        L->list[i + 1] = L->list[i];
    }
    
    L->list[index] = element;       /*插入元素到第i个位置*/	
    L->length = L->length+1;          /*将顺序表长增1*/
    
    return true;

}


bool delete(ArrayList *L,int index,DataType *element)
{
    
    if (!L)
    {
         printf("空指针\n");
        return false;
    }
    else if(L->length <= 0)
    {
        printf("顺序表已空不能进行删除!\n");
        return false;
    }
    else if((index < 0) || (index > L->length - 1))
    {
        printf("删除位置不合适!\n");
        return false;
    }
    
    if (element) {          //非空指针
        *element = L->list[index];
    }

    for (int i = index ; i < L->length; i++)
    {
        L->list[index] = L->list[index + 1];
    }
    L->length = L->length - 1;
    
    return true;
    
}

int length(ArrayList L)
{
    return L.length;
}

void clear(ArrayList *L)
{
    if(L)           //非空指针
    {
        L->length = 0;
    }

}



