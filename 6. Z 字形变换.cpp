//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//
//请你实现这个将字符串进行指定行数变换的函数：
//
//string convert(string s, int numRows);
//

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> nums(min(numRows, (int)s.size()));
        if(numRows == 1)
            return s;
        int tag = -1;
        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(idx == 0 || idx == numRows - 1)
                tag = -tag;

            nums[idx] += s[i];
            idx += tag;

        }
        string ss;
        for(auto j: nums)
            ss += j;

        return ss;
    }
};

//
//int main(){
//    string s = "PAYPALISHIRING";
//    Solution a;
//    string ss = a.convert(s, 3);
//    cout<<ss<<endl;
//    return 0;
//}