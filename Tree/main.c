//
//  main.c
//  Tree
//
//  Created by cl on 4/12/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
//#include "BitTree.h"
#include "HuffmanTree.h"

void test1();
void test2();
void test3();
void test4();

int main(int argc, const char * argv[])
{

    
    HuffmanTree *ht;
    char datas[] = {'A','B','C','D'};
    int weights[] = {1,3,6,9};
    
    createH(&ht, datas, weights, 4);
    
    preOrderTraverseH(ht);
    
    destroyH(&ht);
    
    

    return 0;
}

//void test1(){
//    BitTree *root;
//    
//    init(&root);
//    printf("please input BitTree:");
//    create(&root);
//    
//    preOrderTraverse(root);
//    
//    inOrderTraverse(root);
//    
//    postOrderTraverse(root);
//    
//    destroy(&root);
//
//}
//
//void test2(){
//    BitTree *root;
//    
//    init(&root);
//    printf("please input BitTree:");
//    create(&root);
//    
//    printLevel(root);
//    
//    destroy(&root);
//    
//}
//
//void test3(){
//    BitTree *root;
//    
//    init(&root);
//    printf("please input BitTree:");
//    create(&root);
//    
//    int count;
//    
//    preOrderTraverseAndCount(root, &count);
//    
//    printf("count = %d\n",count);
//    
//    destroy(&root);
//    
//}
//
//void test4(){
//    
//    BitTree *root;
//    
//    init(&root);
//    printf("please input BitTree:");
//    create(&root);
//    
//    printf("leafNum = %d\n",getLeafNum(root));
//    printf("notLeafNum = %d\n",getNotLeafNum(root));
//    printf("depth = %d\n",getDepth(root));
//    
//    destroy(&root);
//}
//
