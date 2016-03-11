/*======================================================
    > File Name: quikSort.cpp
    > Author: lyh
    > E-mail:  
    > Other : 递归快速排序  O(nlogn)   不稳定
    > Created Time: 2016年03月11日 星期五 14时50分27秒
 =======================================================*/

#include<iostream>

//一趟排序
int quikPass(int a[],int low,int high)
{
//    std::swap(a[low],a[(low+high)/2]);  //取中间值作为关键字，只需与头交换
    int key = a[low];  //在头部挖坑
    while(low < high)
    {
        //从后往前扫，找到比关键字小的数填到low位置的坑中
        while(low < high && a[high] >= key)
            high--;
        a[low] = a[high];
        //从前往后扫，找到比关键字大的数填到high位置的坑中
        while(low < high && a[low] < key )
            low++;
        a[high] = a[low];
    }
    //关键字放到最后一个坑中
    a[low] = key;
    return low;
}

void quikSort(int a[],int low,int high)
{
    int   h=0;
    if(low < high)
    {
        h = quikPass(a,low,high);
        quikSort(a,low,h-1);
        quikSort(a,h+1,high);
    }
}

int main()
{
    int   a[] = {12,11,17,1,0,32,6,2,99,32,45,7};
    quikSort(a,0,11);
    for(int i = 0;i<12;i++)
        std::cout<<a[i]<<" ";
    return 0;
}
