/**
给定两个字符串 text1 和 text2,返回这两个字符串的最长公共子序列 的长度.如果不存在 公共子序列 ,返回 0.
一个字符串的 子序列 是指这样一个新的字符串:它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串.
两个字符串的公共子序列是这两个字符串所共同拥有的子序列.

解题思路：使用基于二维数组的动态规划
 状态转移方程
               0  if i = 0 or j = 0
 dp[i][j] =    dp[i-1][j-1] + 1 if text1[i] = text2[j]
               max(dp[i-1][j], dp[i][j-1])
*/







# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        if(text1.size() == 0 || text2.size() == 0)
            return 0;
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j<= len2; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
