//请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
//如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
# include <iostream>
# include <vector>
# include <stack>


using namespace std;


class TreeNode{
public:
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){}

    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> res1 = NLR(root1);
        vector<int> res2 = NLR(root2);
        return res1 == res2;
    }

    vector<int> NLR(TreeNode * root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<TreeNode *> stk;
        TreeNode * p = root;
        while (p || !stk.empty())
        {
            if (p)
            {
                if (p->left == nullptr && p->right == nullptr)
                    res.push_back(p->val);
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.top();
                stk.pop();
                p = p->right;
            }
        }
        return res;
    }
};
