//
//  main.c
//  Graph
//
//  Created by cl on 4/20/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>

#include "MatrixGraph.h"
//#include "LinkGraph.h"

int main(int argc, const char * argv[])
{
    PathMatrix path;
    ShortPathLength dist;
    
    
    MatrixGraph G;
    createMatrixGraph(&G);
    Dijkstra(G,0,path,dist);
    displayMatrixGraph(G);
    
    printf("%s到各顶点的最短路径长度为：\n",G.vex[0]);
    for(int i=0;i<G.vexNum;++i)
        if(i!=0)
            printf("%s-%s:%d\n",G.vex[0],G.vex[i],dist[i]);
    
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            printf("%d,",path[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

//void test1(){
//
//    MatrixGraph G;
//    createMatrixGraph(&G);
//    displayMatrixGraph(G);
//}

//void test2(){
//
//LinkGraph G;
//createLinkGraph(&G);
//DFSTraverse2(G, 0);
//destroyLinkGraph(&G);
//}

//    LinkGraph G;
//    createLinkGraph(&G);
//
//    CriticalPath(G);
//
//    destroyLinkGraph(&G);

