/*======================================================
    > File Name: rect_area.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月10日 星期日 15时10分58秒
 =======================================================*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;
//矩形元素
typedef struct Rect
{
    int  high; //高
    int  width;//宽
}Rect;

//求最大连续矩形的面积
class MaxInnerRec
{
public:
    //方法1：借助栈，减少比较次数
    int countArea(vector<int> A,int n)
    {
        int      max = 0; //保存最大连续矩形的面积
        Rect     r;  //入栈矩形
        A.push_back(0); //末尾添加一个高度为0的矩形，保证最终全部出栈
        stack<Rect>    s;
        for(int i=0;i<n+1;i++)
        {
            //tmp1保存已出栈的合并矩形
            Rect   tmp2,tmp1 = {0,0};
            while(!s.empty() && s.top().high >= A[i])
            {//栈空或者当前矩形比栈顶矩形低
                tmp2 = s.top();
                s.pop();
                tmp1.width = tmp1.width + tmp2.width;
                tmp1.high = tmp2.high;
                int   m = tmp1.width*tmp1.high;//合并弹出的矩形
                if(m >max)//如果弹出的合并矩形面积较大时更新max
                    max = m;
            }
            r.high = A[i];
            r.width = tmp1.width + 1;
            s.push(r); //新矩形入栈
        }
        return  max;
    }
    //方法2：穷举
    int countArea2(vector<int> A,int n)
    {
        int max=0;
        int min=0;//保存当前最低的矩形
        for(int i=0;i<n;i++)
        {
            min = A[i];
            int         m=0;
            for(int j=i;j<n;j++)
            {
                if(A[j] < min)
                    min = A[j];
                m = min*(j-i+1);
                if(m > max)
                    max = m;
            }
        }
        return max;
    }
};

int main()
{
    vector<int>    A = {2,7,9,4,1};
    MaxInnerRec    m;
    cout<<m.countArea2(A,A.size())<<endl;
    return 0;
}
