/*
未知 整数数组 arr 由 n 个非负整数组成。

经编码后变为长度为 n - 1 的另一个整数数组 encoded ，其中 encoded[i] = arr[i] XOR arr[i + 1] 。例如，arr = [1,0,2,1] 经编码后得到 encoded = [1,2,3] 。

给你编码后的数组 encoded 和原数组 arr 的第一个元素 first（arr[0]）。

请解码返回原数组 arr 。可以证明答案存在并且是唯一的。

*/
# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size()+1;
        vector<int> arr(n);
        arr[0] = first;
        for(int i = 0; i < encoded.size(); i++){
            arr[i+1] = encoded[i] ^ arr[i];
        }
        return arr;
    }
};

/*int main(){

    Solution s;
    vector<int> encoded{1,2,3};
    int first = 1;
    vector<int> arr = s.decode(encoded, first);
    for(auto i: arr)
        cout<<i<<endl;
    return 0;
}*/
