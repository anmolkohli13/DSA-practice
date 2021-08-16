/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

//Function to get the left view of the binary tree.
void leftViewUtil(vector<int>&vec,struct Node *root, int level,int *max_level)
{
    //if root is null, we simply return.
    if (root==NULL)  return;
    
    //if this is the first node of its level then it is in the left view.
    if (*max_level < level)
    {
        //storing data of current node in list.
        vec.push_back(root->data);
        *max_level = level;
    }
    
    //calling function recursively for left and right subtrees of current node. 
    leftViewUtil(vec,root->left, level+1, max_level);
    leftViewUtil(vec,root->right, level+1, max_level);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(struct Node *root)
{
    int max_level = 0;
    vector<int> vec;
    leftViewUtil(vec,root, 1, &max_level);
    //returning the list.
    return vec;
}
