/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int find(TreeNode *root,int &h)
    {
        if(root==NULL)return 0;
        
        int lh=find(root->left,h);
        int rh=find(root->right,h);
        h=max(h,lh+rh+1);
        
        return max(lh,rh)+1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int h=-1;
        find(root,h);
        return h-1;      
    }
};
