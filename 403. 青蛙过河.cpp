//一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。
//
//给你石子的位置列表 stones（用单元格序号 升序 表示），请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。
//
//开始时，青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格 1 跳至单元格 2 ）。
//
//如果青蛙上一步跳跃了k个单位，那么它接下来的跳跃距离只能选择为k - 1、k或k + 1 个单位。另请注意，青蛙只能向前方（终点的方向）跳跃。

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));//当前石头的下标以及到达该石头的步长
        dp[0][0] = true;
        //下标　　步长
        //０　　　０
        //1      0, 1
        //2      0, 1, 2
        //到达i下标时，其步长最大为i
        //若stones[i] - stones[j] > i  则步长不够，不能到达
        for(int i = 1; i < n; i++){
            if((stones[i] - stones[i-1]) > i)
                return false;
        }
        //到达i时，步长最大为i，使用j遍历所有可能的步长
        for(int i = 1; i< n; i++){
            for(int j = i-1; j>= 0; j--){
                int dis = stones[i] - stones[j];
                if(dis > j+1)
                    break;
                dp[i][dis] = dp[j][dis-1] || dp[j][dis]  || dp[j][dis+1];
                if(i == n-1 && dp[i][dis])
                    return true;
            }
        }
        return false;

    }
};
//
//int main(){
//    Solution s;
//    vector<int> stones{0,1,3,5,6,8,12,17};
//    if(s.canCross(stones))
//        cout<<"yes"<<endl;
//    else
//        cout<<"no"<<endl;
//    return 0;
//}