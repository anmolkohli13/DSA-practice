/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head = NULL, *temp = NULL;
    while(ptr1 && ptr2){
    if(ptr1->data == ptr2->data){
    Node* newNode = new Node(ptr1->data);
    if(head) temp->next = newNode;
    
    else head = newNode;
    
    temp = newNode;
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
    }
    else if(ptr1->data < ptr2->data) ptr1 = ptr1->next;
    else ptr2 = ptr2->next;
    }
    return head;
    
}
