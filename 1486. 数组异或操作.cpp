/*
给你两个整数，n 和 start 。

数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。

请返回 nums 中所有元素按位异或（XOR）后得到的结果

*/

# include <iostream>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        for(int i = 1; i < n; i++){
            int cur = start + 2 * i;
            res = res ^ cur;
        }
        return res;
    }
};
