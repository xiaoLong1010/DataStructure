//
//  MatrixGraph.c
//  basic
//
//  Created by cl on 4/23/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "MatrixGraph.h"

#define MAX 1000



void createMatrixGraph(MatrixGraph *G){

    printf("请输入有向网的顶点数，弧数(比如5,6):");
    scanf("%d,%d",&(G->vexNum),&(G->arcNum));
    
    printf("请输入%d个顶点的值，顶点之间用空格分隔:",G->vexNum);
    for (int i = 0; i < G->vexNum; i++) {
        scanf("%s",G->vex[i]);
    }
    
    //初始化邻接矩阵
    for (int i = 0; i < G->vexNum; i++) {
        for (int j = 0; j < G->vexNum; j++) {
            (G->arcs[i][j]).adj = INFINITY;
            (G->arcs[i][j]).info = NULL;
        }
    }
    
    printf("请输入%d条弧的弧头 弧尾 权值(以空格作为间隔): \n",G->arcNum);
    for (int k = 0; k < G->arcNum; k++) {
        
        VertexType vex1,vex2;
        VRType w;
        scanf("%s%s%d",vex1,vex2,&w);
        
        int i = locateVertex(*G, vex1);
        if (i < 0) {
            printf("该弧头不存在\n");
        }
        
        int j = locateVertex(*G, vex2);     
        if (j < 0) {
             printf("该弧尾不存在\n");
        }
        
        G->arcs[i][j].adj = w;
    }
    
}

void displayMatrixGraph(MatrixGraph G){
	
    printf("有向网具有%d个顶点%d条弧，顶点依次是: ",G.vexNum,G.arcNum);
	for(int i = 0;i < G.vexNum;i++)				/*输出网的顶点*/
		printf("%s ",G.vex[i]);
	printf("\n有向网G的:\n");			/*输出网N的弧*/
	printf("序号i=");
	for(int i = 0;i < G.vexNum;i++){
        printf("%8d",i);
    }
		
	printf("\n");
    
	for(int i = 0;i < G.vexNum;i++){
		printf("%8d",i);
        
		for(int j = 0;j < G.vexNum;j++){
            printf("%8d",G.arcs[i][j].adj);
        }
			
		printf("\n");
	}
    
}


int locateVertex(MatrixGraph G,VertexType v){
    
    for (int i = 0; i < G.vexNum; i++) {
        if (strcmp(G.vex[i], v) == 0) {
            return i;
        }
    }
    return -1;
}

void Kruskal(MatrixGraph G){
    int vertexs[MaxSize];   //顶点的集合，
    
    int verNum = G.vexNum;  //图的顶点数
    
    int min = 789;    //最小的权值,应该足够的大
    int minI,minJ;  //最小权值的顶点索引
    
    
    //初始化顶点集合
    for (int i = 0; i < verNum; i++) {
        vertexs[i] = i;
    }
    
    for (int k = 0; k < verNum - 1; k++) {
       
        //遍历矩阵上三角
        for (int i = 0  ; i < verNum; i++) {
            for (int j = i; j < verNum; j++) {
                if ( (G.arcs[i][j].adj > -1) && (G.arcs[i][j].adj < min) && (vertexs[i] != vertexs[j])) {
                    min = G.arcs[i][j].adj;
                    minI = i;
                    minJ = j;
                }
            }
        }
        printf("%s-%s\n",G.vex[minI],G.vex[minJ]);
        
        G.arcs[minI][minJ].adj = -1;  //
        
        min = 698;
        
        //
        for (int i = 0; i < verNum; i++) {
            if (vertexs[i] == vertexs[minJ]) {
                vertexs[i] = vertexs[minI];
            }
        }
        
    }
}

void Dijkstra(MatrixGraph G,int v0,PathMatrix path,ShortPathLength dist){

    int final[MaxSize];
    int verNum = G.vexNum;
    int min = 1000;
    
    for (int i = 0; i < verNum; i++) {
        final[i] = 0;
        dist[i] = G.arcs[v0][i].adj;        //初始化最短路径长度
        
        for (int j = 0; j < verNum; j++) {
            path[i][j] = 0;     //表示从顶点v0到顶点i的最短路径是否经过顶点j，1表示经过，0表示不经过
        }
        
        if (dist[i] < INFINITY) {
            path[i][v0] = 1;    //表示从顶点v0到顶点i的最短路径，经过顶点v0
            path[i][i] = 1;
        }
    }
    
    //v0顶点并入集合S
    dist[v0] = 0;
    final[v0] = 1;
    
    int v = 0;
    
    //v0到其余verNum-1个顶点的最短路径
    for (int i = 1; i < verNum; i++) {
        
        min = MAX;
        
        //找出最小的dist
        for (int j = 0; j < verNum; j++) {
            if ( (!final[j]) && (dist[j] < min)) {
                v = j;
                min = dist[j];
            }
        }
        final[v] = 1;
        
        for (int j = 0; j < verNum; j++) {
            
            //如果经过顶点v，在到j，路径更短
            if ((!final[j]) && (min < MAX) && (G.arcs[v][j].adj < MAX) && (min + G.arcs[v][j].adj < dist[j])) {
                dist[j] = min + G.arcs[v][j].adj;
                for (int k = 0; k < verNum; k++) {      //先经过顶点v，在到顶点j
                    path[j][k] = path[v][k];
                }
                path[j][j] = 1;
            }
        }
    }
}


void Floyd(MatrixGraph G,PathsMatrix paths,ShortPathsLength dists)
{
    int verNum = G.vexNum;
    
    for (int i = 0; i < verNum; i++) {
        
        for (int j = 0; j < verNum; j++) {
            dists[i][j] = 0;        //初始化i到j的最短路径的长度
            
            for (int k = 0; k < verNum; k++) {      //初始化i到j的最短路径经过的定点，1为经过，0为不经过
                paths[i][j][k] = 0;
            }
            
            if (G.arcs[i][j].adj < INFINITY) {      //定点i到j之间有一条弧
                dists[i][j] = G.arcs[i][j].adj;
                paths[i][j][i] = 1;
                paths[i][j][j] = 1;
            }
            
        }
        

    }
    
    for (int k = 0; k < verNum; k++) {
        
        //i到j的路径，中间插入顶点k
        for (int i = 0; i < verNum; i++) {
        for (int j = 0; j < verNum; j++) {
            
            //如果i从k再到j，小于i到j
            if ((G.arcs[i][k].adj < INFINITY) && (G.arcs[k][j].adj < INFINITY) && (G.arcs[i][k].adj + G.arcs[k][j].adj < dists[i][j])) {
                dists[i][j] = G.arcs[i][k].adj + G.arcs[k][j].adj;
                //更新i到j的路径
                for (int v = 0; v < verNum; v++) {
                    paths[i][j][v] = paths[i][k][v] || paths[k][j][v];
                }
                
            }
            

            
        }
        }
        
    }
    

}
