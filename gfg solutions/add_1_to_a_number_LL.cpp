/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
    
        while(curr != NULL)
        {
            Node *nex = curr->next;
            
            curr->next = prev;
            prev = curr;
            
            curr = nex;
        }
    
    return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        head = reverse(head);
        
        Node *curr = head, *prev = head;
    
        int sum = (curr->data + 1);
        curr->data = sum % 10;
        int carry = sum / 10;
    
        curr = curr->next;
        
        while(curr != NULL)
        {
            sum = (curr->data + carry);
            curr->data = sum % 10;
            carry = sum / 10;
            
            prev = curr;
            
            curr = curr->next;
        }
        
        if(carry)
        {
            prev->next = new Node(carry);
        }
        
        head = reverse(head);
        
        return head;
    }
};
