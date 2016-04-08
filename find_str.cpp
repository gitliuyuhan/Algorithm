/*======================================================
    > File Name: 
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月07日 星期四 12时49分26秒
 =======================================================*/

/*找出包含指定子串的字符串，不区分大小写，并按子串匹配个数递减排序*/

#include<iostream>
#include<vector>
#include<string>

class Coder {
public:
    //有多少个匹配的子串
    int find_str(std::string str,std::string s){
        int str_len = str.length();
        int s_len = s.length();
        int n=0;
        for(int i=0;i<str_len;i++){
            int j = 0;
            if(str[i] == s[j] || str[i]-s[j]==32 || s[j]-str[i]==32){
                int  k = i;
                while(k < str_len && (str[k] == s[j] || str[i]-s[j]==32 || s[j]-str[i]==32)){
                    j++;
                    k++;
                    if(j == s_len){
                        n++;
                        break;
                    }
                }              
            }
        }
        return n;
    }
    std::vector<std::string> findCoder(std::vector<std::string> A, int n) {
        //存储符合的字符串
        std::vector<std::string>    v;
        //字符串对应的子串匹配个数
        std::vector<int>            count(n);
        for(int i=0;i<n;i++){
            int n = find_str(A[i],"coder");
            if(n){
                v.push_back(A[i]);
                int len = v.size();
                int j = 0;
                count[len-1] = n;
                //递减，插入排序
                for(j = len-1;j>0 && n > count[j-1];j--){
                    count[j] = count[j-1];
                    v[j] = v[j-1];
                }
                count[j] = n;
                v[j] = A[i];
            }
        }
        return v;
    }
};

int main()
{
    Coder   coder;
    std::vector<std::string>    A={"coder","dccoderrlcoderxxpicoderhcoderbiwcoderdcoderrcodermcoderdbvcodertrwvycoderimvcoderuswfccoderczecoderczncoderkfuehcoderocoderiuvccoderfwcodervdiycoderifqjcoder","vxroicoderdqcoderfvcodermtyrcoderlcoderwrygcoder","hcoderwzmjccoderamfmvcoderazmcoderhcodersnuccoderceocodermsmifcoderpwpcodertqbqcoderentbcoderxsgpkcoderrqrbcoderucoder"};
    std::vector<std::string> v = coder.findCoder(A,A.size());
    for(int i=0;i<v.size();i++)
        std::cout<<v[i]<<std::endl;
    return 0;
}
