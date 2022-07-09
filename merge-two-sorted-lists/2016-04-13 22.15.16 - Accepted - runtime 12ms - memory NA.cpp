/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
namespace lists {
    size_t size(ListNode *h) {
        size_t s = 0;
        while (h) {s+=1; h=h->next;}
        return s;
    }
    int remove(ListNode **paddr) {
        ListNode *p = *paddr;
        if (p==NULL) return 0;
        *paddr = p->next;
        // free(p)
        return 1;
    }
    ListNode ** get(ListNode **it, int k) {
        for (;k>0;k--) {
            it = & ((*it)->next);
        }
        return it;
    }
    size_t dump(ListNode *h) {
        size_t s = 0;
        while (h) {s+=1; cout<<h->val<<" "; h=h->next;}
        cout<<" # len="<<s<<endl;
        return s;
    }

    ListNode * merge_inc_list(ListNode *l1, ListNode *l2) {
        if (! l1) return l2;
        if (! l2) return l1;
        
        ListNode *h = 0;
        ListNode *it = NULL;
        if (l1->val < l2->val) {
            h = l1; l1 = l1->next;
        } else {
            h = l2; l2 = l2->next;
        }
        it = h;
        while (l1 || l2) {
            if (! l1) {
                it->next = l2;
                return h;
            }
            if (! l2) {
                it->next = l1;
                return h;
            }
            if (l1->val < l2->val) {
                it -> next = l1; it = l1; l1 = l1->next;
            } else {
                it -> next = l2; it = l2; l2 = l2->next;
            }
        }
        return h;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
                return lists::merge_inc_list(l1,l2);

    }
};