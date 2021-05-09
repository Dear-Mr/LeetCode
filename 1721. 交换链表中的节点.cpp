/*
给你链表的头节点 head 和一个整数 k 。

交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。*/

# include <iostream>

using namespace std;






class ListNode{
public:
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur = head, *k_1 = head, *k_2 = head;
        int cnt = 1;
        while(cur){
            if(cnt == k)
                k_1 = cur;
            if(cnt > k)
                k_2 = k_2->next;
            cur = cur->next;
            cnt++;
        }
        int temp = k_2->val;
        k_2->val = k_1->val;
        k_1->val = temp;
        return head;
    }
};
