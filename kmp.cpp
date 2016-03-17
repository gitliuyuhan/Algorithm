/*======================================================
    > File Name: kmp.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月17日 星期四 15时27分18秒
 =======================================================*/

#include<iostream>
#include<string.h>

//求部分匹配表
void getNext(char str[],int next[])
{
    int len = strlen(str);
    int k = 0;  //记录当前位置前面已经匹配了多少个
    next[0] = 0;
    for(int i=1;str[i] != '\0';i++)
    {
        //匹配中断，找出新的匹配串
        while(k>0 && str[i]!=str[k])
        {
            k = next[k-1]; //匹配串结束位置
        }
        if(str[i] == str[k])
            k++;
        next[i] = k;
    }
}

int kmp(char text[],char str[])
{
    int       start = -1;
    int       i,j;
    const int len = strlen(str);
    int       next[len];
    //获取匹配表
    getNext(str,next);

    for(i=0,j=0;text[i]!='\0' && str[j]!='\0';i++,j++)
    {
        if(text[i] != str[j])
        {
            //匹配中断时，向前跳
            j = next[j-1];
        }   
    }
    //匹配成功
    if( j == len)
        start = i-j;
    return start;
}

int main()
{
    char text[]="abcdabcabcdabcde";
    char str[]="abcde";
    int start = kmp(text,str);
    std::cout<<start<<std::endl;
    return 0;
}
