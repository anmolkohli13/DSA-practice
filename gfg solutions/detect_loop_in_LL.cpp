class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* f)
    {
        // your code here
        
        struct Node *p,*q;
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
