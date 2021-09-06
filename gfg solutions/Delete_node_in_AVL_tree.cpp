/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

    int max(int a, int b)
    {
        return (a > b)? a : b;
    }
    Node* newNode(int key)
    {
        Node* node = new Node(key);
        // node->key = key;
        // node->left = NULL;
        // node->right = NULL;
        // node->height = 1; // new node is initially
        //                   // added at leaf
        return(node);
    }
    
    int height(Node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
     
        // Perform rotation
        x->right = y;
        y->left = T2;
     
        // Update heights
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;
     
        // Return new root
        return x;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
     
        // Perform rotation
        y->left = x;
        x->right = T2;
     
        // Update heights
        x->height = max(height(x->left),   
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;
     
        // Return new root
        return y;
    }
    int getBalance(Node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    
    /* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node * minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
Node* deleteNode(Node* root, int key)
{
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->data )
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( key > root->data )
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node *temp = root->left ?
                         root->left :
                         root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's
            // data to this node
            root->data = temp->data;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }
 
    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));
 
    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced,
    // then there are 4 cases
 
    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
