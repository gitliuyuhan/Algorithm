/*======================================================
    > File Name: helix_matrix.cpp
    > Author: lyh
    > E-mail:  
    > Other :  顺时针打印矩阵
    > Created Time: 2016年04月21日 星期四 18时54分51秒
 =======================================================*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
    vector<int>  result;
    int x1=0,y1=0; //左上角坐标
    int x2=n-1,y2=m-1; //右下角坐标

    while(x1<x2 && y1<y2){
        for(int i=y1;i<y2;i++)
            result.push_back(mat[x1][i]);
        for(int i=x1;i<x2;i++)
            result.push_back(mat[i][y2]);
        for(int i=y2;i>y1;i--)
            result.push_back(mat[x2][i]);
        for(int i=x2;i>x1;i--)
            result.push_back(mat[i][y1]);
        x1++;
        y1++;
        x2--;
        y2--;
    }
    //左上角坐标和右下角坐标移到了同一行
    if(x1==x2){
        for(int i=y1;i<=y2;i++)
            result.push_back(mat[x1][i]);
        return result;
    }
    //左上角和右下角在同一列
    if(y1==y2){
        for(int i=x1;i<=x2;i++)
            result.push_back(mat[i][y1]);
        return result;
    }
    return result;
}
