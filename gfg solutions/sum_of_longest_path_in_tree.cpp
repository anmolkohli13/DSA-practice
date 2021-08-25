/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    void leveltrv(Node *root,int level,int &max_level,int &ans,int sum){

    if(root==NULL){
        if(level>=max_level){
            max_level=level;
            ans = max(sum,ans);
        }
        return;
    
    }
    
    leveltrv(root->left,level+1,max_level,ans,sum+root->data);
    leveltrv(root->right,level+1,max_level,ans,sum+root->data);
    
    }
    int sumOfLongRootToLeafPath(Node* root)
    { 
        if(root==NULL)
            return 0;
        int ans=0;
        int max_level = -1;
        leveltrv(root,0,max_level,ans,0);
        return ans;
    }
};
