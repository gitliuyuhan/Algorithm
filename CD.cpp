/*======================================================
    > File Name: CD.cpp
    > Author: lyh
    > E-mail:  
    > Other : 共n首歌，间隔至少1秒，CD容量l秒，每首歌s秒，每张CD中的歌曲数量不能被13整除，求CD数量
    > Created Time: 2016年04月27日 星期三 19时56分14秒
 =======================================================*/

#include<iostream>

using namespace std;

int CD_num(int n,int s,int l)
{
    int count = 0;
    int t = (l+1)/(s+1); //每张能容纳的数量
    if(t<=n) //一张CD装不下
    {
        if(t % 13 ==0)
            t--; //容纳数量减1调整
        count  = n/t; //需要的CD数量
        if(n % t !=0) 
        {
            int k = n % t;
            if(k % 13 == 0)
            {
                if((t-1) % 13 !=0) //尝试将前一张CD中取一首歌过来
                {
                    count++;
                }
                else
                {//尝试从前一张CD中取两首歌过来
                    if(k+2 <= t) //能否多加2首歌
                        count++;
                    else
                        count += 2; //将最后一张CD做减1调整
                }
            }
            else
                count++; //正好每张CD装t首歌
        }
    }
    else
    {
        if(n % 13 ==0)
            count = 2;
        else
            count = 1;
    }
    return count;
}

int main()
{
    int n,s,l;
    while(cin>>n>>s>>l)
    {
        cout<<CD_num(n,s,l)<<endl;
    }
    return 0;
}
