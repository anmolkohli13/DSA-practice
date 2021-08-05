/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    if(head1 == NULL || head2 == NULL)
    return 0;
    
    Node *a = head1;
    Node *b = head2;
    
    while(a != b)
    {
        a = a == NULL? head2 : a->next;
        b = b == NULL? head1 : b->next;
    }
    return a->data;
    
    // below approach does not work now or with negative values in LL 
    // Node *temp = head1;
    // while(temp){
    //     temp->data = -1 * temp->data;
    //     temp = temp->next;
    // }
    // temp = head2;
    // int ans = -1;
    // while(temp){
    //     if(temp->data < 0){
    //         ans = -temp->data;
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // return ans;
    
}
