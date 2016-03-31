/*======================================================
    > File Name: pwd.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月31日 星期四 19时52分00秒
 =======================================================*/

#include<stdio.h>

#define LEN  1
#define BIG  2
#define LOW  4
#define INT  8

int strtype(char *str)
{
    int   i=0;
    int   flag = 0;
    for(i=0;str[i] != '\0';i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            flag = flag | BIG;
        if(str[i] >= 'a' && str[i] <= 'z')
            flag = flag | LOW;
        if(str[i] >= '0' && str[i] <= '9')
            flag = flag | INT;
    }
    if(i >= 5)
        flag = flag | LEN;
    if(flag == 15)
        return 1;
    else
        return 0;
}

void print(int flag)
{
    if(flag)
        printf("Correct\n");
    else
        printf("Too weak\n");
}

int main()
{
    char str[101];
    int  result[1000];
    int  i=0;
    int  j=0;
    while(scanf("%s",str) != EOF)
    {
        result[i] = strtype(str);
        i++;
    }
    for(j=0;j<i;j++)
        print(result[j]);
    return 0;
}
