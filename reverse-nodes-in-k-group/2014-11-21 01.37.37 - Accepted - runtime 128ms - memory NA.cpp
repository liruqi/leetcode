/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) return head;
        ListNode **p = & head;
        ListNode * ret = head;
        while(p && *p) {
            ListNode *end = *p;
            for(int i=0; i<k; i++) {
                if (! end) return ret;
                end = end->next;
            }
            
            ListNode *last = *p;
            ListNode *it = (*p)->next;
            (*p)->next = end;
            
            while (it != end) {
                ListNode *next = it->next;   
                it->next = last;
                last = it;
                it = next;
            }
            if (*p == head) {
                ret = last;
                p = & (head->next);
            }
            else {
                it = *p;
                *p = last;
                p = &(it->next);
            }
            
        }
        return ret;
    }
};


