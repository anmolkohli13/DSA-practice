//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   
        //Node *lnode, *rnode;
        if(!root){
        return NULL;
        }
        
        if(n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);
        
        else if(n2 > root->data && n1 > root->data)
        return LCA(root->right, n1, n2);
        
        return root;
}

