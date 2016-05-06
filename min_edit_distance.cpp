/*======================================================
    > File Name: min_edit_distance.cpp
    > Author: lyh
    > E-mail:  
    > Other : 字符串的最短编辑距离
    > Created Time: 2016年05月06日 星期五 08时55分36秒
 =======================================================*/

#include<iostream>
#include<string.h>

int min(int a,int b,int c)
{
    int min = a < b ? a : b;
    return (min < c ? min : c);
}

//str1经过插入或删除或替换变为str2的最小操作次数
int minEditDistance(char* str1,char* str2)
{
    const int len1 = strlen(str1+1);
    const int len2 = strlen(str2+1);
    int dp[len1+1][len2+1] = {0};
    //dp[i][j] str1的前i个字符与str2的前j个字符的最小编辑距离
    for(int i = 0;i<=len1;i++)
    {
        for(int j = 0;j<=len2;j++)
        {
            if(i==0 && j==0) //dp[0][0]设置为0
                dp[i][j] = 0;
            if(i==0 && j>0)
                dp[i][j] = j;
            if(j==0 && i>0)
                dp[i][j] = i;
            if(i>0 && j>0)
            {
                if(str1[i] == str2[j])
                    dp[i][j] = dp[i-1][j-1] + 0;
                else
                    //删除，插入，替换三种操作比较
                    dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    char str1[1000];
    char str2[1000];
    std::cin>>str1+1>>str2+1; //字符串下标从1开始
    std::cout<<minEditDistance(str1,str2)<<std::endl;
    return 0;
}


