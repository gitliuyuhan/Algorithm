/*======================================================
    > File Name: prime.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月22日 星期二 19时36分40秒
 =======================================================*/

#include<stdio.h>
#include<math.h>    

int is_prime(int k)
{
    int   i,n;
    if(k ==1 )
        return 0;
    n = sqrt(k);
    for(i = 2; i <= n; i++)
    {
        if(k % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int    n = 1000000;
    int    i;
    for(i = 1;i<=n;i++)
    {
        if(is_prime(i))
            printf("%7d ",i);
    }
    return 0;
}
