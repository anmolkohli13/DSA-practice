class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        
        Node *prev = NULL;
        return validate(root,prev);
        
    }
    
    bool validate(Node *node, Node *&prev)
    {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->data >= node->data) return false;
        prev = node;
        return validate(node->right, prev);
    }
    
};
