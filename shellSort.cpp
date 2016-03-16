/*======================================================
    > File Name: shellSort.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 17时14分39秒
 =======================================================*/

#include<iostream>

void shellSort(int a[],int len)
{
    for(int d = len/2;d>0; d = d/2)
    {
        for(int i = 0;i<len-d;i++)
        {
            int j,k = a[i+d]; 
            for(j = i+d;j>=d && k < a[j-d] ;j = j-d)
            {
                a[j] = a[j-d];
            }
            a[j] = k;
        }
    }
}

int main()
{
    int a[] = {10,23,12,45,22,0,10,11,2,21};
    shellSort(a,10);
    for(int i =0;i<10;i++)
        std::cout<<a[i]<<" "<<std::endl;
    return 0;
}
