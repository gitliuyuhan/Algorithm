/*======================================================
    > File Name: strlen_re.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月15日 星期五 12时17分15秒
 =======================================================*/

#include<stdio.h>

//strlen递归写法
int strlen_re(const char* str)
{
    if(str == NULL)
        return -1;
    if(*str == '\0')
        return 0;
    else
        return strlen_re(str+1)+1;
}

int main()
{
    char str[10] = "12345";
    printf("%d\n",strlen_re(str));
    return 0;
}
