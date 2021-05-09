/*
给你一个长度为 n 的字符串数组 names 。你将会在文件系统中创建 n 个文件夹：在第 i 分钟，新建名为 names[i] 的文件夹。

由于两个文件 不能 共享相同的文件名，因此如果新建文件夹使用的文件名已经被占用，系统会以 (k) 的形式为新文件夹的文件名添加后缀，其中 k 是能保证文件名唯一的 最小正整数 。

返回长度为 n 的字符串数组，其中 ans[i] 是创建第 i 个文件夹时系统分配给该文件夹的实际名称。

*/

# include <iostream>
# include <vector>
# include <unordered_set>
# include <unordered_map>
# include <string>
# include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

        vector<string> res;
        unordered_map<string, int > table;
        for(const string& name: names){
            if(table.count(name)){
                // 如果 name 已经被使用了，则暴力搜索后面小括号中需要添加的数字
                for(int k = table[name] + 1; ; k ++){
                    string new_name = name + "(" + to_string(k) + ")";
                    if(!table.count(new_name)){
                        res.push_back(new_name);
                        table[name]++;
                        table[new_name] = 0;
                        break;
                    }
                }
            }
            else{
                res.push_back(name);
                table[name] = 0;
            }
        }
        return res;
    }
};


/*
int main(){
    Solution s;
    vector<string> names{"gta","gta(1)","gta","gta(2)"};
    vector<string> res = s.getFolderNames(names);
    for(auto i: res)
        cout<<i<<endl;
    return 0;
}*/
