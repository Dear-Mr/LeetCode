//给你一个字符串s，以及该字符串中的一些「索引对」数组pairs，其中pairs[i] =[a, b]表示字符串中的两个索引（编号从 0 开始）。
//
//你可以 任意多次交换 在pairs中任意一对索引处的字符。
//
//返回在经过若干次交换后，s可以变成的按字典序最小的字符串


# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <algorithm>
# include <queue>
# include <hash_map>

using namespace std;

class  DisjointSetUnion{
public:
    DisjointSetUnion(int _n){
        n = _n;
        rank.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i< n; i++)
            parent[i] = i;
    }

    int find(int x){
        return parent[x] == x?parent[x]:find(parent[x]);
    }

    void unionSet(int x, int y){
       int rootX = find(x);
       int rootY = find(y);
       if(rootX == rootY)
           return;

       if(rank[rootX] == rank[rootY]){
           parent[rootX] = y;
           rank[rootY]++;
       }
       else if(rank[rootX] < rank[rootY]){
           parent[rootX] = rootY;
       }
       else
           parent[rootY] = rootX;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int n;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.size() == 0)
            return s;
        int len = s.size();
        //使用并查集 将可以互换的元素下标放置同一个集合
        DisjointSetUnion unionSet(len);
        for(auto it: pairs){
            unionSet.unionSet(it[0], it[1]);
        }

        // 使用map用来记录并查集中一个集合对应的root下标，以及按升序排列的对应字符
        map<int,  priority_queue<char,vector<char>, greater<char>>> hashmap;

        for(int i = 0; i< len; i++){
            int root = unionSet.find(i);
            if(hashmap.count(root) == 0){
                priority_queue<char,vector<char>, greater<char>> cur;
                cur.push(s[i]);
                hashmap.insert(make_pair(root,cur));
            }
            else
                hashmap[root].push(s[i]);
        }

        // 遍历s的下标，找到其对应的root下标，并用最小的字符填入该位置
        string res;
        for(int i = 0; i < len; i++){
            int root = unionSet.find(i);
            char cur = hashmap[root].top();
            hashmap[root].pop();
            res += cur;
        }
        return res;
    }
};

//int main(){
//    string s = "dcab";
//    vector<vector<int>> pairs{{0,3},{1,2}, {0,2}};
//    Solution ss;
//    string res = ss.smallestStringWithSwaps(s, pairs);
//    cout<<res<<endl;
//    return 0;
//}