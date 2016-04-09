/*======================================================
    > File Name: LU_RD_Road.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月09日 星期六 17时03分32秒
 =======================================================*/

/*每次只能向右或向下走，有障碍物（-1表示）的地方不可走，
 *求从左上角到（x,y）位置共有多少种走法？
 */


#include<iostream>
#include<vector>

//计算左上角到(x,y)有多少种走法
int road_num(std::vector<std::vector<int>> &a,std::vector<std::vector<int>> &result,int x,int y)
{
    int  d1,d2;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 && j==0)
                result[i][j] = 1;
            else if(a[i][j] == -1)
                result[i][j] = 0;
            else
            {
                //到该位置上方的格子的走法数
                d1 = (i-1)<0 ? 0:result[i-1][j];
                //到该位置左边的格子的走法数
                d2 = (j-1)<0 ? 0:result[i][j-1];
                //相加就是到该位置的走法数
                result[i][j] = d1+d2;
            }            
        }
    }
    return result[x][y];   
}

//输出求解结果
void print(std::vector<std::vector<int>> &result,int x,int y)
{
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
            std::cout<<result[i][j]<<" ";
        std::cout<<std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>>  a = {{0,0,-1,0},{-1,0,0,-1},{0,-1,0,0},{0,0,0,0}};
    std::vector<std::vector<int>>  result(4,{0,0,0,0});
    std::cout<<road_num(a,result,3,3)<<std::endl;
    print(result,3,3);
    return 0;
}
