class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int n = lists.size();
        if (n==0)   return NULL;
        if (n==1)   return lists[0];
        if (n==2)   return mergeTwoLists(lists[0], lists[1]);
        vector<ListNode*> left(lists.begin(), lists.begin()+n/2);
        vector<ListNode*> right(lists.begin()+n/2, lists.end());
        return mergeTwoLists(mergeKLists(left), mergeKLists(right));
    }
};