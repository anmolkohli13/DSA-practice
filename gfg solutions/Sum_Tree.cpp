/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool isLeaf(Node* root)
    {
        if(root->left==NULL&&root->right==NULL)
        return true;
        
        return false;
    }
    bool isSumTreeUtil(Node* root,int *sum)
    {
        if(root==NULL)
        {
            *sum=0;
            return true;
        }
        if(isLeaf(root)==true)
        {
            *sum=root->data;
            return true;
        }
        int ls=0,rs=0;
        bool lst=isSumTreeUtil(root->left,&ls);
        bool rst=isSumTreeUtil(root->right,&rs);
        
        *sum=ls+rs+root->data;
        
        return (root->data==ls+rs)&&lst&&rst;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         int sum=0;
         return isSumTreeUtil(root,&sum);
    
    }
};
