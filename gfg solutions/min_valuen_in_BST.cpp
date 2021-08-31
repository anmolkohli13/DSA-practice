int minValue(Node* root)
{
    // Code here
    
    if(root == NULL)
    return 0;
    
    while(root->left)
    {
        root = root->left;
    }
    return root->data;
    
    
}
