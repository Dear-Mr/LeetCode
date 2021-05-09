//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//
//如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
//假设环境不允许存储 64 位整数（有符号或无符号）。



# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            if(res > INT32_MAX/10 || (res == INT32_MAX/10 && pop > INT32_MAX % 10)) return 0;
            if(res < INT32_MIN/10 || (res == INT32_MIN/10 && pop < INT32_MIN % 10)) return 0;
            res = res * 10 + pop;
        }
        return res;
    }
};
