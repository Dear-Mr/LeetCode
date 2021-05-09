//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
//
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0, cnt = 0;
        while(right < nums.size()){
            if(right == 0 || nums[right] == nums[right - 1]){
                ++cnt;
                if(cnt <= 2)
                    nums[left++] = nums[right];
            }
            else {
                cnt = 1;
                nums[left++] = nums[right];
            }
            ++right;
        }
        return left;

    }
};

//int main(){
//    vector<int> nums{0,0,1,1,1,1,2,3,3};
//    Solution s;
//    int len = s.removeDuplicates(nums);
//    cout<<len<<endl;
//    for(auto i :nums)
//        cout<<i<<endl;
//    return 0;
//}


