/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
     void traverse(Node* r,Node* &head,Node* &prev){
        if(r==NULL){
            return;
        }
        traverse(r->left,head,prev);
        if(head==NULL){
            head=r;
            prev=r;
        }
        else{
            r->left=prev;
            prev->right=r;
            prev=r;
        }
        traverse(r->right,head,prev);
    }
    Node * bToDLL(Node *root)
    {
        Node* head=NULL;
        Node* prev=NULL;
        traverse(root,head,prev);
        return head;
    }
};
