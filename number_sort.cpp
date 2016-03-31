/*======================================================
    > File Name: str.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月22日 星期二 19时58分03秒
 =======================================================*/

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>

void get_num_str(std::vector<std::string>  &v,char* str)
{
    char   s[20];
    for(int i = 0; str[i] != '\0';i++)
    {
        if(str[i] != ',')
        {
            int  j;
            for(j = 0;str[i]!=',' && str[i] != '\0';j++)
            {
                s[j] = str[i];
                i++;
            }
            s[j] = '\0';
            v.push_back(s);
        }  
        if(str[i] == '\0') 
            break;
    }      
}

void get_num(std::vector<int> &vn,std::vector<std::string> &v)
{
    for(int i = 0; i<v.size();i++)
    {
        int  tmp = atoi(v[i].c_str());
        vn.push_back(tmp);
    }
    sort(vn.begin(),vn.end());
}


int main()
{
    std::vector<std::string>   v;
    std::vector<int>           vn;
    char    str[1024];
    std::cin>>str;
    get_num_str(v,str);
    get_num(vn,v);
    for(int i=0;i < vn.size();i++)
    {
        std::cout<<vn[i];
        if(i != vn.size()-1)
            std::cout<<",";
    }
    std::cout<<std::endl;
    return 0;
}
