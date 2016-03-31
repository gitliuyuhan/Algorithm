/*======================================================
    > File Name: str.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月28日 星期一 20时27分34秒
 =======================================================*/

#include<stdio.h>
#include<stdlib.h>

//获取连续 . 的个数
int get_n(char* str)
{
    int   i=0;
    int   n=0;
    for(i = 0;str[i] != '\0';i++)
    {
        if(str[i] == '.' && str[i+1] != '\0' && str[i+1] == '.')
            ++n;
    }
    return n;
}

int main()
{
    int     n,m;
    //待求字符串
    char    *str;
    //置换操作
    int     i = 0;
    //置换位置
    int     x;
    //置换字符
    char    c;
    int     j=0,k=2;
    int     result[100];          
    while(k)
    {
        scanf("%d %d",&n,&m);
        str = (char*)malloc(n+1);
        scanf("%s",str);
        for(i = 0;i<m;i++)
        {
            scanf("%d %c",&x,&c);
            str[x-1] = c;
            result[j] = get_n(str);
            j++;
        }   
        free(str);
        k--;
    }
    for(i = 0;i<j;i++)
    {
        printf("%d\n",result[i]);
    }
    return 0;
}
