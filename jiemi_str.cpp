/*======================================================
    > File Name: jiemi_str.cpp
    > Author: lyh
    > E-mail:  
    > Other : 数字表示它前面的字符串重复了几次，比如：a3bc2表示aaabcbc
    > Created Time: 2016年04月23日 星期六 20时42分20秒
 =======================================================*/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>

using namespace std;

const char* com_baiyi_decode(const char* str)
{
    string    s("");
    string    result("");
    int       n=1;
    int       len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            n = str[i]-'0';
            //提取数字
            for(i=i+1;i<len && str[i]>='0' && str[i]<='9';i++)
            {
                n = n*10+(str[i]-'0');
            }
            //将重复字符串连接起来
            for(int j=0;j<n;j++)
                result = result + s;
            if(i<len)
            {
                s = "";
                n = 1;
                i--;
            }
            else
                break;
        }
        else
        {
            //提取字符串
            s.push_back(str[i]);           
        }
    }
    len = result.length();
    char* ss = (char*)malloc(sizeof(char)*(len+1));
    for(int i=0;i<len;i++)
        ss[i] = result[i];
    ss[len] = '\0';
    return ss;
}

int main()
{
    char str[100];
    while(cin>>str)
    {
        cout<<com_baiyi_decode(str)<<std::endl;
    }
    return 0;
}
