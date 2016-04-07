/*======================================================
    > File Name: main.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月28日 星期一 19时10分07秒
 =======================================================*/

#include<stdio.h>
#include<stdlib.h>

typedef struct ArrayType
{
    int   len;    //数组长度
    int   *array; //数组
}ArrayType;

//判断数组下标是否越界
int isArrayFull(ArrayType *arr,int index)
{
    if(index+1 > arr->len)
        return 1;
    else
        return 0;
}

//扩展数组空间为size
void extendArray(ArrayType *arr,int size)
{
    int  *p,*tmp;
    int  i;

    p = (int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
        p[i] = arr->array[i];
    tmp = arr->array;
    arr->array = p;
    p = tmp;
    free(p);
    arr->len = size;
}

//初始化数组
void initArray(ArrayType *arr,int len)
{
    if(len > 0)
    {
        arr->array = (int*)malloc(sizeof(int)*len);
        arr->len = len;
    }
    else
    {
        arr->array = NULL;
        arr->len = 0;
    }
}

//销毁数组
void freeArray(ArrayType arr)
{
    if(arr.array)
        free(arr.array);
    arr.len = 0;
}

//输出数组元素
void printArray(ArrayType* arr)
{
    int  i=0;
    for(i = 0;i<(arr->len);i++)
        printf("%d ",arr->array[i]);
    printf("\n");
}

int main()
{
    ArrayType   arr;
    initArray(&arr,2);
    arr.array[0] = 1;
    arr.array[1] = 2;
    printArray(&arr);
    if(isArrayFull(&arr,3))
    {
        extendArray(&arr,4);
        arr.array[2] = 3;
        arr.array[3] = 4;
    }
    printArray(&arr);
    freeArray(arr);
    return 0;
}

