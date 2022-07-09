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
    ListNode ** get(ListNode **it, size_t k) {
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

    /*
     Swap two list nodes
     
     o -> p -> q -> r
     o -> q@ p -> r
     o -> q -> p -> r
     
     handled case p->next == q
     case q->next == p is not handled
     */
    pair<ListNode *, ListNode *> swap(ListNode **paddr, ListNode **qaddr) {
        if (! paddr || !qaddr) {
            ListNode *nil = NULL;
            return make_pair(nil,nil);
        }
        ListNode *p = (*paddr);
        ListNode *q = (*qaddr);
        std::swap(p->next, q->next);
        if (q->next == q) {
            q->next = p;
            *paddr = q;
        } else {
            std::swap(*paddr, *qaddr);
        }
        return make_pair(q, p);
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ((! head) || (! head->next)) {
            return head;
        }
        ListNode *ret = NULL;
        ListNode **it = & head;
        while ((*it) && (*it)->next) {
            pair<ListNode *, ListNode *> p = lists::swap(it, &((*it)->next));
            if (! ret) ret = p.first;
            it = & (p.second->next);
#if DEBUG
            lists::dump(ret);
#endif
        }
        return ret;
    }
};