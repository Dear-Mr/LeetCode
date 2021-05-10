/*
给你一个整数数组 bloomDay，以及两个整数 m 和 k 。

现需要制作 m 束花。制作花束时，需要使用花园中 相邻的 k 朵花 。

花园中有 n 朵花，第 i 朵花会在 bloomDay[i] 时盛开，恰好 可以用于 一束 花中。

请你返回从花园中摘 m 束花需要等待的最少的天数。如果不能摘到 m 束花则返回 -1 。
*/

//=========================================
//解题思路：
//定义isEnough函数  判断当前日期是否能够完成所需的花束
//当天数较少时，不能够完成所需花束
//随着天数的增多，完成所需花束的可能性越大
//为了找到最小的天数，可以使用二分查找
//========================================



# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m * k)
            return -1;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while(left < right){
            int mid = left + (right - left)/2;
            if(isEnough(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left > right?-1:left;
    }
    bool isEnough(vector<int>& bloomDay, int m, int k, int d){
        int cnt = 0;
        int cur = 0;
        for(auto i: bloomDay){
            if(i <= d)
                cur += 1;
            else
                cur = 0;
            if(cur >= k){
                cnt += 1;
                cur -= k;
            }
        }
        return cnt >= m;
    }
};

//int main(){
//    Solution s;
//    vector<int> bloomDay{1,10,3,10,2};
//    int m = 3, k = 1;
//    int res = s.minDays(bloomDay, m, k);
//    cout<<res<<endl;
//    return 0;
//}