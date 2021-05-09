//给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
//
//丑数 就是只包含质因数 2、3 和/或 5

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n ==0) // 0不是丑数
            return false;
        vector<int> nums{5,3,2};
        for(auto i: nums){
            while(n % i == 0)
                n = n/i;
        }
        if(n == 1)
            return true;
        else
            return false;

    }
};

//int main(){
//    Solution s;
//    int n = 6;
//    if(s.isUgly(n))
//        cout<<"yes"<<endl;
//    else
//        cout<<"no"<<endl;
//    return 0;
//}