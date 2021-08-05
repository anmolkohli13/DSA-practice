/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
         if(head == NULL)
             return NULL;
         ListNode *cur = head;
         ListNode *nex = cur->next;

         while(nex != NULL)
         {
             if(cur->val != nex->val)
             {
                 cur = nex;
                 nex = nex->next;

             }
             else
             {
                 cur->next = nex->next;
                 delete nex;
                 nex = cur->next;
             }

         }

         return head;
        
    }
};
