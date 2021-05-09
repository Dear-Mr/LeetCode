# include <iostream>
# include <vector>

using namespace  std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};


ListNode* build(vector<int> nums){
    if(nums.empty())
        return nullptr;
    else if(nums.size() == 1){
        auto p = new ListNode(1);
        return p;
    }
    else{
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        for(auto i:nums){
            ListNode* p = new ListNode(i);
            cur->next = p;
            cur = cur->next;
        }
        return head->next;
    }
}

//int main(){
//    vector<int> nums{1,2,3,4,5};
//    ListNode* head = build(nums);
//    while(head){
//        cout<<head->val<<endl;
//        head = head->next;
//    }
//    return 0;
//}

