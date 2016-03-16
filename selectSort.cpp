/*======================================================
    > File Name: selectSort.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 16时20分26秒
 =======================================================*/

#include<iostream>

void selectSort(int a[],int len)
{
    int  k=0;
    for(int i=0;i<len-1;i++)
    {
        k = i;
        for(int j = i+1;j<len;j++)
        {
            if(a[k] < a[j])
                k = j;
        }
        if(k != i)
        {
            int tmp = a[i];
            a[i] = a[k];
            a[k] = tmp;
        }
    }
}

int main()
{
    int a[] = {20,10,3,56,2,23,4,20,0,8};
    selectSort(a,10);
    for(int i=0;i<10;i++)
    {
        std::cout<<a[i]<<" "<<std::endl;
    }
    return 0;
}
