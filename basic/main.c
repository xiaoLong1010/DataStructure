//
//  main.c
//  basic
//
//  Created by cl on 4/3/14.
//  Copyright (c) 2014 cl. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//不允许有同名的外部函数，内部函数和外部函数可以同名
static int sum(int a,int b)
{
    return  a + b;
}

struct test {
    int a;
};

int main(int argc, const char * argv[])
{

    // insert code here...
    
    int a = 2;
    
    int arr[a]; //c99特性
    
    arr[0] = 1;
    
    
//    struct test a = {1};
//    
//    struct test b = a;
//    printf("%d",b.a);
    return 0;
}

