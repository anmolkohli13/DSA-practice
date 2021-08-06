/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node *merge(Node *l1,Node *l2)
    {
        if(!l1)
        return l2;
        if(!l2)
        return l1;
        
        if(l1->data < l2->data)
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }
    
    
    Node* mergeSort(Node* head) {
        // your code here
        
        if(head == NULL || head->next == NULL)
        return head;
        
        Node *first=head,*second=head->next;
        
        while(second && second->next)
        {
            first = first->next;
            second = second->next->next;
        }
        
        Node *newHead = first->next;
        first->next = NULL;
        
        return merge(mergeSort(head),mergeSort(newHead));
        
        
    }
};
