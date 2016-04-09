/*======================================================
    > File Name: r.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月09日 星期六 19时47分11秒
 =======================================================*/

/* n*m的格子内选择起点到终点的所有走法，
 * 左右只能选择一个方向，上下也只能选择一个方向
 */

#include<iostream>
#include<vector>
using namespace std;

class Visit {
public:
    int countPath(vector<vector<int> > map, int n, int m) {
        // write code here
        int x1,y1,x2,y2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] == 1){//找到起点
                    x1 = i;
                    y1 = j;
                }
                if(map[i][j]==2){//找到终点
                    x2 = i;
                    y2 = j;
                }
            }
        }
        int x_flag = (x2-x1)>0 ? 1:-1;//判断向右还是向左
        int y_flag = (y2-y1)>0 ? 1:-1;//判断向下还是向上
        vector<vector<int> >  result(n,vector<int>(m));
        for(int i = x1;(x2-i)*x_flag>=0;i+=x_flag){
            for(int j=y1;(y2-j)*y_flag>=0;j+=y_flag){
                if(i==x1 && j==y1)
                    result[i][j] = 1;
                else if(map[i][j]==-1)
                    result[i][j] = 0;//不可达
                    else{
                    //考虑到越界情况    
                    int d1 = (x1-(i-x_flag))*x_flag>0 ? 0:result[i-x_flag][j];
                    int d2 = (y1-(j-y_flag))*y_flag>0 ? 0:result[i][j-y_flag];
                    result[i][j] = d1+d2;
                 }
            }
        }
        return result[x2][y2];
    }
};

int main()
{
    Visit   visit;
    vector<vector<int> >   map = {{0,2,0},{1,0,0}};
    std::cout<<visit.countPath(map,2,3)<<std::endl;
    return 0;
}
