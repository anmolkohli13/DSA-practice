//Function to insert a node in a BST.

Node* insert(Node* root, int key)
{
    // Your code here
    
    if (root==NULL) {
        root = new Node(key);
        return root;
    } 
    else if (key < root->data)
    root->left = insert(root->left, key);
    
    else if (key > root->data)
    root->right = insert(root->right, key);
    
    return root;
}
