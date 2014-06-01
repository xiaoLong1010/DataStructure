//
//  LinkGraph.h
//  basic
//
//  Created by cl on 4/27/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#ifndef basic_LinkGraph_h
#define basic_LinkGraph_h

typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;

#define INFINITY -1			/*定义一个无限大的值*/

#define MaxSize 50				/*最大顶点个数*/
typedef int DataType;			/*栈元素类型定义*/

#define StackSize 100
typedef struct
{
    DataType stack[StackSize];
    int top;
}SeqStack;

typedef enum {DG,DN,UG,UN} GraphKind; 	/*图的类型：有向图、有向网、无向图和无向网*/

typedef struct node
{
	int index;					/*弧的终点的索引*/
	InfoPtr *info; 				/*与弧或边的相关信息*/
    int weight;
    struct node *next;      //顶点的下一条弧
}ArcNode;

typedef struct VexNode {
    VertexType data;
    ArcNode *first;

}VexNode,GraphVertexs[MaxSize];


typedef struct {
    GraphVertexs vertexs;
    int vexNum,arcNum;
    GraphKind kind;

} LinkGraph;

int visited[MaxSize]; /* 访问标志数组*/

void DFSTraverse(LinkGraph G);
void DFS(LinkGraph G,int v);
int FirstAdjVertex(LinkGraph G,VertexType v);
int NextAdjVex(LinkGraph G,VertexType v,VertexType w);
void DFSTraverse2(LinkGraph G,int v);
void BFSTraverse(LinkGraph G);
void visit(VertexType v);
int locate(LinkGraph G,VertexType v);
void createLinkGraph(LinkGraph *G);
void destroyLinkGraph(LinkGraph *G);

int TopologicalSort(LinkGraph G);

int TopologicalOrder(LinkGraph G,SeqStack *T);

int CriticalPath(LinkGraph G);

#endif
