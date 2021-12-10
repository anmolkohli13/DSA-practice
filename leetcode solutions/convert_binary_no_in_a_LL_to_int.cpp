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
    int getDecimalValue(ListNode* head) {
        
//         ListNode *curr = head;
//         int count = 0;
//         while(curr)
//         {
//             count++;
//             curr = curr->next;
//         }
//         int i = 1,ans = 0;
//         curr = head; 
        
//         while(curr)
//         {
//             ans += (curr->val)*pow(2,count-i);
//             i++;
//             curr = curr->next;
//         }
//         return ans;
        int ans = 0;
        for(; head; head = head -> next) 
            ans = (ans << 1) + head -> val;
        return ans;
        
    }
};
