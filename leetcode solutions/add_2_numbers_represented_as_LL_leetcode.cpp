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
    
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr != NULL){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        
        // ListNode *curr1 = reverse(first);
        // ListNode *curr2 = reverse(second);
        ListNode *curr1 = first;
        ListNode *curr2 = second;
        int carry=0,sum;
        
        sum = (curr1->val + curr2->val);
        ListNode *ansNode = new ListNode(sum % 10);
        ListNode *ansHead = ansNode;
        carry = sum / 10;
        curr1 = curr1->next;
        curr2 = curr2->next;
        
        //loops to cover rest of the operations
        while(curr1 != NULL and curr2 != NULL){
            sum = (curr1->val + curr2->val +carry);
            ansNode -> next = new ListNode(sum % 10);
            ansNode = ansNode -> next;
            carry = sum / 10;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1 != NULL){
            sum = (curr1->val + carry);
            ansNode -> next = new ListNode(sum % 10);
            ansNode = ansNode -> next;
            carry = sum / 10;
            curr1 = curr1->next;
        }
        while(curr2 != NULL){
            sum = (curr2->val + carry);
            ansNode -> next = new ListNode(sum % 10);
            ansNode = ansNode -> next;
            carry = sum / 10;
            curr2 = curr2->next;
        }
        if(carry){
            ansNode ->next = new ListNode(carry);   
        }
        //return reverse(ansHead);
        return ansHead;
        
    }
};
