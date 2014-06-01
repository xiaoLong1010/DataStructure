//
//  LinkGraph.c
//  basic
//
//  Created by cl on 4/27/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkGraph.h"

static int ve[MaxSize];
static int vl[MaxSize];

//无向图
void createLinkGraph(LinkGraph *G){


    
	printf("请输入图的顶点数,边数(逗号分隔): ");
	scanf("%d,%d",&(G->vexNum),&(G->arcNum));
    
	printf("请输入%d个顶点的值:\n",G->vexNum);
	for(int i = 0;i < G->vexNum;i++)			/*将顶点存储在头结点中*/
	{
		scanf("%s",((G->vertexs)[i]).data);
		((G->vertexs)[i]).first = NULL;	/*将相关联的顶点置为空*/
	}
	printf("请输入弧尾和弧头权值(以空格作为间隔):\n");
	for(int k = 0;k < G->arcNum;k++)			/*建立边链表*/
	{
        VertexType v1,v2;				/*定义两个顶点v1和v2*/
        int weight;
        scanf("%s%s%d",v1,v2,&weight);
        
		int i = locate(*G,v1);
		int j =locate(*G,v2);
        
		/*j为弧头i为弧尾创建邻接表*/
		ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
		p->index = j;
		p->info = NULL;
        p->weight = weight;
		p->next = G->vertexs[i].first;
		G->vertexs[i].first = p;
        
		/*i为弧头j为弧尾创建邻接表*/
//		p = (ArcNode*)malloc(sizeof(ArcNode));
//		p->index = i;
//		p->info = NULL;
//		p->next = G->vertexs[j].first;
//		G->vertexs[j].first = p;
	}
	(*G).kind=UG;

}


int locate(LinkGraph G,VertexType v){

    for (int i = 0; i < G.vexNum; i++) {
        if (strcmp((G.vertexs[i]).data, v) == 0) {
            return i;
        }
    }
    
    return -1;
}

void destroyLinkGraph(LinkGraph *G){

    for (int i = 0;i < G->arcNum; i++) {
        ArcNode *first = ((G->vertexs)[i]).first;
        ((G->vertexs)[i]).first = NULL;
        
        while(first != NULL) {    //销毁第i个节点的所有弧
            ArcNode *tmp = first;
            first = first->next;
            free(tmp);
        }
    }
    G->arcNum = 0;
    G->vexNum = 0;

}

void DFSTraverse2(LinkGraph G,int v){

	int visited[MaxSize],top;
	
    ArcNode *stack[MaxSize],*p;
    
	for(int i = 0;i < G.vexNum;i++)			/*将所有顶点都添加未访问标志*/
		visited[i] = 0;
    
	visit(G.vertexs[v].data);		/*访问顶点v并将访问标志置为1，表示已经访问*/
	visited[v] = 1;
    
	top = -1;							/*初始化栈*/
	p = G.vertexs[v].first;			/*p指向顶点v的第一个邻接点*/
     
	while((top > -1) || (p != NULL) )
	{
		while(p != NULL){
            
            if(visited[p->index] == 1){     /*如果p指向的顶点已经访问过，则p指向下一个邻接点*/ 
                printf("if--%s\n",G.vertexs[p->index].data);
                p = p->next;
            
            } else{
				visit(G.vertexs[p->index].data);	/*访问p指向的顶点*/
				visited[p->index] = 1;
				stack[++top] = p;		/*保存p指向的顶点*/
				p = G.vertexs[p->index].first;/*p指向当前顶点的第一个邻接点*/
			}
        }

        
		if(top > -1)
		{
			p = stack[top--];			/*如果当前顶点都已经被访问，则退栈*/
            printf("stack--%s\n",G.vertexs[p->index].data);
			p = p->next;			/*p指向下一个邻接点*/
		}
	}

}

void visit(VertexType v){
    printf("%s\n",v);
}

void InitStack(SeqStack *S)
/*将栈初始化为空栈只需要把栈顶指针top置为0*/
{
    S->top=0;	/*把栈顶指针置为0*/
}
int StackEmpty(SeqStack S)
/*判断栈是否为空，栈为空返回1，否则返回0*/
{
    if(S.top==0)			/*判断栈顶指针top是否为0*/
        return 1;			/*当栈为空时，返回1；否则返回0*/
    else
        return 0;
}
int GetTop(SeqStack S, DataType *e)
/*取栈顶元素。将栈顶元素值返回给e，并返回1表示成功；否则返回0表示失败。*/
{
    if(S.top<=0)		/*在取栈顶元素之前，判断栈是否为空*/
    {
        printf("栈已经空!\n");
        return 0;
    }
    else
    {
        *e=S.stack[S.top-1];	/*在取栈顶元素*/
        return 1;
    }
}
int PushStack(SeqStack *S,DataType e)
/*将元素e进栈，元素进栈成功返回1，否则返回0.*/
{
    if(S->top>=StackSize)				/*在元素进栈前，判断是否栈已经满*/
    {
        printf("栈已满，不能进栈！\n");
        return 0;
    }
    else
    {
        S->stack[S->top]=e;			/*元素e进栈*/
        S->top++;					/*修改栈顶指针*/
        return 1;
    }
}
int PopStack(SeqStack *S,DataType *e)
/*出栈操作。将栈顶元素出栈，并将其赋值给e。出栈成功返回1，否则返回0*/
{
    if(S->top<=0)		/*元素出栈之前，判断栈是否为空*/
    {
        printf("栈已经没有元素，不能出栈!\n");
        return 0;
    }
    else
    {
        S->top--;			/*先修改栈顶指针，即出栈*/
        *e=S->stack[S->top];	/*将出栈元素赋值给e*/
        return 1;
    }
}
int StackLength(SeqStack S)
/*求栈的长度，即栈中元素个数，栈顶指针的值就等于栈中元素的个数*/
{
    return S.top;
}
void ClearStack(SeqStack *S)
/*将栈初始化为空栈只需要把栈顶指针top置为0*/
{
    S->top=0;	/*把栈顶指针置为0*/
}


int TopologicalSort(LinkGraph G){
    
    int inDegrees[MaxSize];     //每个顶点的入度
    int verNum = G.vexNum;
    
    int count = 0;
    
    SeqStack stack;
    //初始化入度
    for (int i = 0; i < verNum; i++) {
        inDegrees[i] = 0;
    }
    
    //计算每个顶点的度数
    for (int i = 0; i < verNum; i++) {
        ArcNode *arcNode = G.vertexs[i].first;
        
        while (arcNode != NULL) {
            inDegrees[arcNode->index]++;
            arcNode = arcNode->next;
        }
    }
    
    //入度为零的顶点入栈
    InitStack(&stack);
    
    for (int i = 0;i < verNum;i++) {
        if (inDegrees[i] == 0) {
            PushStack(&stack, i);
        }
    }

    while (!StackEmpty(stack)) {
        
        int index;                  //入度为零的顶点
        PopStack(&stack, &index);   //出栈
        
        count++;
        printf("%s\n",G.vertexs[index].data);   //打印顶点
        
        ArcNode *arcNode = G.vertexs[index].first;
        
        while (arcNode != NULL) {
            inDegrees[arcNode->index]--;
            if (inDegrees[arcNode->index] == 0) {       //入度为零的顶点入栈
                PushStack(&stack, arcNode->index);
            }
            arcNode = arcNode->next;   
        }
    }
    
    if (count < verNum) {
        printf("存在闭环\n");
        return 0;
    }
    
    printf("没有闭环\n");
    return 1;
}

int TopologicalOrder(LinkGraph G,SeqStack *T){
    
    int inDegrees[MaxSize];     //每个顶点的入度
    int verNum = G.vexNum;
    
    int count = 0;
    
    SeqStack stack;
    
    //初始化入度,和顶点最早发生时间
    for (int i = 0; i < verNum; i++) {
        inDegrees[i] = 0;
        ve[i] = 0;
    }
    
    //计算每个顶点的度数
    for (int i = 0; i < verNum; i++) {
        ArcNode *arcNode = G.vertexs[i].first;
        
        while (arcNode != NULL) {
            inDegrees[arcNode->index]++;
            arcNode = arcNode->next;
        }
    }
    
    //入度为零的顶点入栈
    InitStack(&stack);
    
    for (int i = 0;i < verNum;i++) {
        if (inDegrees[i] == 0) {
            PushStack(&stack, i);
        }
    }
    
    while (!StackEmpty(stack)) {
        
        int index;                  //入度为零的顶点
        PopStack(&stack, &index);   //出栈
        PushStack(T, index);    //入栈，给逆拓扑排序用
        
        count++;
//        printf("%s\n",G.vertexs[index].data);   //打印顶点
        
        ArcNode *arcNode = G.vertexs[index].first;
        
        while (arcNode != NULL) {
            inDegrees[arcNode->index]--;
            
            // 计算顶点最早发生时间
            int k = arcNode->index;
            if ((ve[index] + arcNode->weight) > ve[k]) {
                ve[k] = ve[index] + arcNode->weight;
            }
            
            if (inDegrees[arcNode->index] == 0) {       //入度为零的顶点入栈
                PushStack(&stack, arcNode->index);
            }
            arcNode = arcNode->next;
        }
    }
    
    if (count < verNum) {
        printf("存在闭环\n");
        return 0;
    }
    
    printf("没有闭环\n");
    return 1;
}

int CriticalPath(LinkGraph G){
    
    SeqStack stack;
    InitStack(&stack);
    
    int e[MaxSize];
    int l[MaxSize];
    
    int verNum = G.vexNum;
    int value = 0;
    
    if (!TopologicalOrder(G, &stack)) {         //有环存在
        return 0;
    }
    
    //计算关键路径长度
    for (int i = 0; i < verNum; i++) {
        if (ve[i] > value) {
            value = ve[i];
        }
    }
    
    //初始化顶点的最晚发生时间
    for (int i = 0; i < verNum; i++) {
        vl[i] = value;
    }
    
    //计算顶点的最晚发生时间
    while (!StackEmpty(stack)) {
        int index;
        PopStack(&stack, &index);
        
        ArcNode *arcNode = G.vertexs[index].first;
        
        while (arcNode != NULL) {
            
            // 计算顶点最晚发生时间
            int k = arcNode->index;
            if ((vl[k] - arcNode->weight) < vl[index]) {
                vl[index] = vl[k] - arcNode->weight;
            }
            
            arcNode = arcNode->next;
        }
        
    }
    
    //计算关键路径顶点
    for (int i = 0; i < G.vexNum; i++) {
        if (ve[i] == vl[i]) {
            printf("%s\n",G.vertexs[i].data);
        }
    }
    //计算关键路径的弧
    int count = 0;
    
    for (int i = 0; i < G.vexNum; i++) {
        ArcNode *arcNode = G.vertexs[i].first;
        
        while (arcNode != NULL) {
            
            // 计算顶点最晚发生时间
            int k = arcNode->index;
            
            count++;
            printf("第%d弧的最早开始时间=%d\n",count,ve[i]);
            printf("第%d弧的最晚开始时间=%d\n",count,vl[k] - arcNode->weight);
            arcNode = arcNode->next;
        }
    }
    
    
    printf("critical path = %d\n",value);
    return 1;
}