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
    bool hasCycle(ListNode *f) {
        
        struct ListNode *p,*q;
        p=q=f;
    
        while(p && q && q->next )
        {
          p=p->next;
          q=q->next;
          q=q?q->next:q;
          if(p==q )
            return 1;
        }
    
        
        return 0;
        
        
    }
};
