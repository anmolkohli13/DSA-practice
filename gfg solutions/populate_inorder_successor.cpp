/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:

    Node *pre = NULL;
    void populateNext(Node *root)
    {
        //code here
        
        if(root == NULL)
        return;
        
        populateNext(root->left);
        
        if(pre)
        pre->next = root;
        
        pre = root;
        
        populateNext(root->right);
        
    }
};
