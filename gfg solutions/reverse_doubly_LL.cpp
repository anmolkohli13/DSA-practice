Node* reverseDLL(Node * head)
{
    //Your code here
    
    while(head)
    {
        Node *nex = head->next;
        head->next = head->prev;
        head->prev = nex;
        
        if(head->prev == NULL)
        {
            break;
        }
        head = head->prev;
        
    }
    return head;
}
