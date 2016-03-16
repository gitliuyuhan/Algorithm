/*======================================================
    > File Name: bubbleSort.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月16日 星期三 15时59分51秒
 =======================================================*/

#include<iostream>

void bubbleSort(int a[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main()
{
    int  a[] = {10,1,3,5,7,2,4,1,6,0};
    bubbleSort(a,10);
    for(int i=0;i<10;i++)
        std::cout<<a[i]<<" "<<std::endl;
    return 0;
}
