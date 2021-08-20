//User function template for C++

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sumTree(Node *node)
    {
        if(node == NULL)
        {
            return 0;
        }
        int d = node->data;
        int lsum = sumTree(node->left);
        int rsum = sumTree(node->right);
        node->data=lsum+rsum;
        
        return d+node->data;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        sumTree(node);
    }
};
