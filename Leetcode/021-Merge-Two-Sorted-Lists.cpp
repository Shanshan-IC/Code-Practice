class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        if (!p) return  q;
        if (!q) return p;
        if (p->val < q->val) {
            p->next = mergeTwoLists(p->next, q);
            return p;
        }
        else {
            q->next = mergeTwoLists(p, q->next);
            return q;
        }
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        if (!p) return  q;
        if (!q) return p;
        ListNode* prev = new ListNode(0);
        ListNode* ans = prev;
        while (p || q) {
            if (p && q) {
                if (p->val < q->val) {
                    ans->next = p;
                    p = p->next;
                }
                else {
                    ans->next = q;
                    q = q->next;
                }
            }
            else if (p) {
                ans->next = p;
                p = p->next;
            }
            else {
                ans->next = q;
                q = q->next;
            }
            ans = ans->next;
        }
        return prev->next;
    }
};