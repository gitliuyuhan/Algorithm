/*======================================================
    > File Name: insertSort.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 16时50分57秒
 =======================================================*/

#include<iostream>

void insertSort(int a[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        int k = a[i+1];
        int j;
        for(j= i+1;j > 0 && a[j-1]>k;j--)
        {
            a[j] = a[j-1];
        }
        a[j] = k;
    }
}

int main()
{
    int a[] = {2,10,6,3,4,2,11,7,9,5};
    insertSort(a,10);
    for(int i=0;i<10;i++)
        std::cout<<a[i]<<std::endl;
    return 0;
}
