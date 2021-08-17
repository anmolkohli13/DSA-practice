/* A binary tree node structure

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

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int isBalancedCheck(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    int lh = isBalancedCheck(root->left);
    if(lh == -1)
    {
        return -1;
    }
    
    int rh = isBalancedCheck(root->right);
    if(rh == -1)
    {
        return -1;
    }
    
    if(abs(lh-rh) > 1)
    {
        return -1;
    }
    else
    {
        return 1 + max(lh, rh);
    }
}

bool isBalanced(Node *root)
{
    if(isBalancedCheck(root) == -1)
    {
        return false;
    }
    return true;
}
};
