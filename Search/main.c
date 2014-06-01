//
//  main.c
//  Search
//
//  Created by csy on 5/25/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include "BinarySearch.h"
#include "BitTree.h"

int main(int argc, const char * argv[])
{
    BitTree *T;
    int keys[] = {37,32,35,62,82,95,73,12,5};
    init(&T);
    
    createBinarySearchTree(&T, keys, 9);
    printTree(T,1);
    printLevel(T);
    destroy(&T);
    
    
    

    return 0;
}

void test1()
{
    int data[] = {1,2,3,4,5,6,7};
    binarySearch(data, 0, 6, 7);
}

