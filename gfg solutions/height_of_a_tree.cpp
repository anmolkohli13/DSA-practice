/*
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
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here 
         int x=0,y=0;
         if(root == NULL)
         return 0;
         x=height(root->left);
         y=height(root->right);
         if(x>y)
         return x+1;
         else
         return y+1;
    }
};
