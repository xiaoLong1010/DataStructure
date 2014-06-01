//
//  BinarySearch.c
//  basic
//
//  Created by csy on 5/25/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include "BinarySearch.h"

//void binarySearch(int datas[],int minIndex,int maxIndex,int searchNum)
//{
//    int midIndex  = 0;
//    
//    //如果没找到searchNum
////    while ((datas[midIndex] != searchNum) && (maxIndex >= minIndex)) {
////        if (datas[midIndex] > searchNum) {
////            maxIndex = midIndex;
////            midIndex = (minIndex + maxIndex) / 2 + 1;
////        }else{
////            minIndex = midIndex;
////            midIndex = (minIndex + maxIndex) / 2 + 1;
////        }
////        
////        
////    }
//    
//    while (minIndex <= maxIndex) {
//        midIndex = (minIndex + maxIndex) / 2;
//        if (datas[midIndex] > searchNum) {
//            maxIndex = midIndex - 1;
//        }else if (datas[midIndex] < searchNum){
//            minIndex = midIndex + 1;
//        }else{
//        
//        }
//    }
////    printf("123");
//    
//    if (datas[midIndex] == searchNum) {
//        printf("the index of %d is %d\n",searchNum,minIndex);
//    }else{
//        printf("the %d is not in the array\n",searchNum);
//    }
//}

void binarySearch(int datas[],int low,int high,int num)
{
    int mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (datas[mid] == num) {
            printf("the index of %d is %d\n",num,mid);
            return;
        }else if (datas[mid] > num){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    
    printf("the %d is not in the array\n",num);
}
