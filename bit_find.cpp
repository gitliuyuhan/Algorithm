/*======================================================
    > File Name: bit_find.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月07日 星期四 08时00分39秒
 =======================================================*/

/*
*二分查找，如果存在多个返回第一个出现的位置
*/

class BinarySearch {
public:
    int getPos(vector<int> A, int n, int val) {
        int left = 0;
        int right = n-1;
        for(int mid = (left+right)/2;left<=right;mid = (left+right)/2){
            if(A[mid] == val){
                while(mid>=0 && A[mid] == val)
                    mid--;
                return mid+1;
            }
            if(A[mid] > val){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
};
