//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

# include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int half = 0;
        while(half < x){
            half = half * 10 + x % 10;
            x /= 10;
        }
        return half == x || half / 10 == x;
    }
};

/*
int main(){
    int x = 121;
    Solution s;
    if(s.isPalindrome(x))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}*/
