/**给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。*/
/*
 * 解题思路：遍历字符串，并使用hashtable记录已经出现的字符，对每一个字符判断是否已经包含，
 * 若未包含则继续；
 * 若已包含，则首先使用hashtable中包含字符的个数与当前的最大子串数相比，更新最大子串数，然后找到当前子串中第一次包含该字符的位置，将该字符的下一个字符作为新子串的首位
 */

# include <iostream>
# include <unordered_map>
# include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> hashtable;
        int lOL = 0;
        int i = 0;
        while(i < s.size())
        {
            if(hashtable.count(s[i]) == 0)
            {
                hashtable[s[i]] = 1;
            }
            else
            {
                lOL = max(lOL, (int)hashtable.size());
                for(int j = i - hashtable.size(); j< i; j++ )
                {
                    if(s[j] == s[i])
                        break;
                    else
                        hashtable.erase(s[j]);

                }
            }
            i++;
        }
        return max(lOL,(int)hashtable.size());
    }
};
