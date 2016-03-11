/*======================================================
    > File Name: quikSortNon.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月11日 星期五 16时03分03秒
 =======================================================*/

#include<iostream>
#include<stack>

//保存边界
typedef struct bound
{
    int  low;
    int  high;
}Bound;

std::stack<Bound>    s;

//一趟排序
int quikPass(int a[],int low,int high)
{
    int key = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= key)
            high--;
        a[low] = a[high];
        while(low < high && a[low] < key)
            low++;
        a[high] = a[low];
    }
    a[low] = key;
    return low;
}

void quikSort(int a[],int low,int high)
{
    Bound     bd;
    bd.low = low;
    bd.high = high;
    s.push(bd);
    while(!s.empty())
    {
        bd = s.top();
        low = bd.low;
        high = bd.high;
        s.pop();
        int h = quikPass(a,low,high);
        if(low < h-1)
        {
            bd.low = low;
            bd.high = h-1;
            s.push(bd); //将边界入栈
        }
        if(h+1 < high)
        {
            bd.low = h+1;
            bd.high = high;
            s.push(bd); //将另一半边界入栈
        }
    }
}

int main()
{
    int  a[] = {11,99,11,20,0,21,3,1,6,18,4,10};
    quikSort(a,0,11);
    for(int i=0;i<12;i++)
        std::cout<<a[i]<<" ";
    return 0;
}
    
