/*======================================================
    > File Name: yanghui.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月09日 星期六 15时42分41秒
 =======================================================*/

#include<stdio.h>

int main()
{
    int  n,i,j;
    int  a[20][20];
    scanf("%d",&n);
    a[0][0] = 1;
    for(i=0;i<n-1;i++)
    {
        a[i+1][0] = 1;
        for(j=0;j<i;j++)
        {
            a[i+1][j+1] = a[i][j] + a[i][j+1];
        }
        a[i+1][i+1] = 1;
    }

    //输出
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
