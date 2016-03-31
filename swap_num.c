/*======================================================
    > File Name: swap_num.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月31日 星期四 20时12分19秒
 =======================================================*/

#include<stdio.h>

int swap_num(int a[],int len)
{
    int  n=0;
    int  i,k,j;
    for(i=0;i<len-1;i++)
    {
        k = a[i+1];
        for(j= i+1;j > 0 && a[j-1]>k;j--)
        {
            a[j] = a[j-1];
            n++;
        }
        a[j] = k;
    }
    return n;
}

int main()
{
    int   t=0;
    int   n=0;
    int   i,j;
    int   a[1000],result[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        result[i] = swap_num(a,n);
    }
    for(i = 0;i<t;i++)
    {
        printf("%d\n",result[i]);
    }
    return 0;
}
