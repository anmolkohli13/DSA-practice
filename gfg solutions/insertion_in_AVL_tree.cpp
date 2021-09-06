/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    
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
    
    
    Node* insertToAVL(Node* node, int key)
    {
        //Your code here
        if (node == NULL)
        return(newNode(key));
 
    if (key < node->data)
        node->left = insertToAVL(node->left, key);
    else if (key > node->data)
        node->right = insertToAVL(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                        height(node->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
    }
};
