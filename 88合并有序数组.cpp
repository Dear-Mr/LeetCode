/**
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
*/

//"该题默认为非递减有序"
# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int p1 = m-1, p2 = n-1, tail = m + n - 1;
       int cur;
       while(p1 >= 0 || p2 >= 0){
           if(p1 == -1)
               cur = nums2[p2--];
           else if(p2 == -1)
               cur = nums1[p1--];
           else if(nums1[p1] > nums2[p2])
               cur = nums1[p1--];
           else
               cur = nums2[p2--];
           nums1[tail--] = cur;
       }
    }
};