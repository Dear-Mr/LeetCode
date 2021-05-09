/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

*/


# include <iostream>
# include <vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int p = 0, q = height.size() - 1;
        while(p < q){
            int cur_area = min(height[p], height[q]) * (q-p);
            max_area = max(max_area, cur_area);
            if(height[p] < height[q])
                p++;
            else
                q--;
        }
        return max_area;
    }
};

/*int main(){
    Solution s;
    vector<int> height{1,1};
    int area = s.maxArea(height);
    cout<<area<<endl;
    return 0;
}*/
