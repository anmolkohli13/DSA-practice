//Function to count number of nodes in BST that lie in the given range.

int helper(Node *root, int l, int h, int &count)
{
    if(!root)
    return 0;
    
    if(root->data < l)
    return helper(root->right,l,h,count);
    
    else if(root->data > h)
    return helper(root->left,l,h,count);
    
    else{
        count++;
        helper(root->left,l,h,count);
        helper(root->right,l,h,count);
        return count;
    }
    return count;
}


int getCount(Node *root, int l, int h)
{
  // your code goes here
  
    if(!root)
    return 0;
        
    int count = 0;
    return helper(root,l,h,count);
}
