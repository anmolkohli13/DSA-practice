class Solution
{
    public:
    
    // Node *reverse(Node *head)
    // {
    //     Node *curr = head;
    //     Node *prev = NULL;
    //     while(curr != NULL)
    //     {
    //         Node *nex = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = nex;
    //     }
    //     return prev;
    // }
    
    Node *compute(Node *head)
    {
        // your code goes here
        
        // if(head == NULL || head->next == NULL)
        // return head;
        
        // Node *curr = reverse(head),*prev = NULL;
        // int max = 0;
        
        // max = curr->data;
        // prev = curr;
        // curr = curr->next;
        
        // while(curr != NULL)
        // {
        //     if(curr->data > max)
        //     {
        //         max = curr->data;
        //         prev = curr;
        //         curr = curr->next;
        //     }
        //     else{
        //         prev->next = curr->next;
        //         Node *temp = curr;
        //         curr = curr->next;
        //         delete temp;
        //     }
        //     // cout<<curr->data<<" ";
        // }
        
        // curr = reverse(curr);
        
        // // while(head)
        // // cout<<head->data;
        
        // return curr;
         if(head->next==NULL)
        return head;
        struct Node *temp=compute(head->next);
        if(temp->data > head->data)
        return temp;
        else
        head->next=temp;
        return head;
        
    }
    
};
   
