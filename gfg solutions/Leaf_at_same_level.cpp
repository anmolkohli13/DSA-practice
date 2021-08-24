/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    
    int maxi(Node* root)
    {
        if(!root) return 0;
        
        return max(maxi(root->left),maxi(root->right))+1;
    }

    int mini(Node* root)
    {
        if(!root) return INT_MAX;
        
        if(!root->left and !root->right) return 1;
        
        return min(mini(root->left),mini(root->right))+1;
    }
    bool check(Node *root)
    {
        //Your code here
        return maxi(root)==mini(root);
    }
};
