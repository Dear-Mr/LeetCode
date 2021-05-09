//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

#include <iostream>
#include <vector>

using namespace std;

//使用二分查找　找到第ｋ小或第ｋ小和第ｋ+1小

class Solution {
public:
    double getKelement(vector<int>& nums1, vector<int>& nums2, int k){
        int size1 = nums1.size(), size2 = nums2.size();
        int index1 = 0, index2 = 0;
        while(true) {
            if (index1 == size1)
                return nums2[index2 + k - 1];
            if (index2 == size2)
                return nums1[index1 + k - 1];
            if (k == 1)
                return min(nums1[index1], nums2[index2]);
            int p1 = min(index1 + (k >> 1) - 1, size1 - 1);
            int p2 = min(index2 + (k >> 1) - 1, size2 - 1);
            if (nums1[p1] < nums2[p2]) {
                k -= (p1 - index1 + 1);
                index1 = p1 + 1;
            } else {
                k -= (p2 - index2 + 1);
                index2 = p2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int k = (n + 1) >> 1;
        if(n % 2 == 1)
            return getKelement(nums1, nums2,k);
        else
            return (getKelement(nums1, nums2, k) + getKelement(nums1, nums2, k + 1)) / 2;

    }
};

//int main(){
//    Solution s;
//    vector<int> nums1{1}, nums2{2,3,4,5,6};
//    double res = s.findMedianSortedArrays(nums1, nums2);
//    cout<<res<<endl;
//    return 0;
//}
