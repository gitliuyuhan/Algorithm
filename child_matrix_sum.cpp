/*======================================================
    > File Name: child_matrix_sum.c
    > Author: lyh
    > E-mail:  
    > Other : 判断一个数组是否可以分成两个和相等的子数组
    > Created Time: 2016年04月22日 星期五 20时22分41秒
 =======================================================*/

#include<iostream>
#include<stdio.h>

//判断是否可以分成两个子数组
int fun(int a[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
        sum = sum + a[i];
    if(sum % 2 != 0)
        return 0;
    const int half = sum/2;
    int dp[half+1] = {0};
    dp[0] = 1;
    //将二维数组简化为一维数组
    for(int i=0;i<n;i++)
    {
        //判断0～i中是否存在和为j
        for(int j=half;j>=a[i];j--)
            dp[j] |= dp[j-a[i]]; //只要判断0～i-1中是否存在和为j或j-a[i]
    }
    return dp[half];
}

//常规二维数组解法
int fun2(int a[],const int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += a[i];
    if(sum % 2 !=0) //和为奇数
        return false;
    const int half = sum/2;
    int dp[n][half+1] = {0};
    for(int i=0;i<n;i++)
    {
        dp[i][0] = true;
        for(int j=half;j>=a[i];j--)
        {
            if(i==0)
                dp[i][j] = (j==a[i]);
            else
                dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i]];
        }
    }
    return dp[n-1][half];
}

int main()
{
    int n;
    while(std::cin>>n)
    {
        const int len = n;
        int a[len];
        for(int i=0;i<len;i++)
            std::cin>>a[i];
        std::cout<<fun2(a,n)<<std::endl;
    }
    return 0;
}
