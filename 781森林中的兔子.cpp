/**
森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在 answers 数组里。

返回森林中兔子的最少数量。
 **/

# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int numRabbits(vector<int>& answers)
//    {
//        unordered_map<int, int> hashtable;
//        for(int i : answers)
//                ++hashtable[i];
//
//        int cnt = 0;
//        for(auto [x,y]:hashtable){//x 兔子的颜色 y 该颜色的数量
//            cnt += ((x+y)/x+1)*(x+1);
//        }
//        return cnt;
//    }
//};

