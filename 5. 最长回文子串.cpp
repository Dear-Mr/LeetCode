//给你一个字符串 s，找到 s 中最长的回文子串。

# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        string lp ;
        for(int l = 1; l<= s.size(); l++){
            for(int i = 0; i + l <= s.size(); i++){
                int j = i + l - 1;
                if(l == 1)
                    dp[i][j] = true;
                else if(l == 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);

                if(dp[i][j] && (l > lp.size()))
                    lp = s.substr(i,l);

            }
        }
        return lp;
    }
};

//int main(){
//    string s =  "cbbd";
//    Solution ss;
//    string res = ss.longestPalindrome(s);
//    cout<<res<<endl;
//    return 0;
//}