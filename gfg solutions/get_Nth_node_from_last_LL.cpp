/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       if(head == NULL)
        return -1;
        
        int count = 0;
        
        Node *curr = head;
        
        while(curr)
        {
            count++;
            curr = curr->next;
        }
        
        curr = head;
        
        if((count-n) >= 0)
        {
            for(int i = 0; i <= count-n-1; i++)
            {
                curr = curr->next;
            }
        
            return curr->data;
        }
        else return -1;
        
        
}
