/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    void rightViewUtil(vector<int>&vec,struct Node *root, int level,int *max_level)
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
        
        rightViewUtil(vec,root->right, level+1, max_level);
        rightViewUtil(vec,root->left, level+1, max_level);
    }
    
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       
        int max_level = 0;
        vector<int> vec;
        rightViewUtil(vec,root, 1, &max_level);
        //returning the list.
        return vec;
    }
};
