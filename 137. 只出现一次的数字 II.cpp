//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        unordered_map<int , int > val_cnt;
        for(int cur : nums){
            ++val_cnt[cur];
        }
        int res;
        for(auto[val, cnt]:val_cnt){
            if(cnt == 1) {
                res = val;
                break;
            }
        }
        return res;
    }
};
//
//int main(){
//
//    return 0;
//}