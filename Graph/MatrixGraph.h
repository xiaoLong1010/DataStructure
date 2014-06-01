//
//  MatrixGraph.h
//  basic
//
//  Created by cl on 4/20/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#ifndef basic_MatrixGraph_h
#define basic_MatrixGraph_h

typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;

#define INFINITY 1000			/*定义一个无限大的值*/

#define MaxSize 50				/*最大顶点个数*/

typedef int PathMatrix[MaxSize][MaxSize];	/*定义一个保存最短路径的二维数组*/
typedef int ShortPathLength[MaxSize];		/*定义一个保存从顶点v0到顶点v的最短距离的数组*/

typedef int PathsMatrix[MaxSize][MaxSize][MaxSize];
typedef int ShortPathsLength[MaxSize][MaxSize];

typedef enum {DG,DN,UG,UN} GraphKind; 	/*图的类型：有向图、有向网、无向图和无向网*/

typedef struct
{
	VRType adj;					/*对于无权图，用1表示相邻，0表示不相邻；对于带权图，存储权值*/
	InfoPtr *info; 				/*与弧或边的相关信息*/
}ArcNode,GraphMatrix[MaxSize][MaxSize];

typedef struct					/*图的类型定义*/
{
	VertexType vex[MaxSize]; 	/*用于存储顶点*/
	GraphMatrix arcs; 				/*邻接矩阵，存储边或弧的信息*/
	int vexNum,arcNum; 			/*顶点数和边（弧）的数目*/
	GraphKind kind; 			/*图的类型*/
}MatrixGraph;


void createMatrixGraph(MatrixGraph *N);
int locateVertex(MatrixGraph N,VertexType v);
void DestroyGraph(MatrixGraph *N);
void displayMatrixGraph(MatrixGraph G);

void Kruskal(MatrixGraph G);

void Dijkstra(MatrixGraph G,int v0,PathMatrix path,ShortPathLength dist);

void Floyd(MatrixGraph G,PathsMatrix path,ShortPathsLength dist);


#endif
