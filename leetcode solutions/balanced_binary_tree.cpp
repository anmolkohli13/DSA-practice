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
// Optimal solution checked from the submissions section
//  int check(TreeNode* root)
//     {
//         if(root==NULL)
//             return 0;
//         int lh=check(root->left);
//         int rh=check(root->right);
//         if(lh==-1)
//             return -1;
//         if(rh==-1)
//             return -1;
//         if(abs(lh-rh)>1)
//             return -1;
//         return max(lh,rh)+1;
//     }
    
//     bool isBalanced(TreeNode* root) {
//         return check(root)!=-1;
//     }
// MY SOLUTION FOR THE PROBLEM
class Solution {
public:
    int height(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        int x = 0,y = 0;
        
        x = height(root->left);
        y = height(root->right);
        
        if(x > y)
            return x+1;
        else return y+1;       
    }
    
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        
        if(abs(left - right) <= 1 && isBalanced(root->left) &&isBalanced(root->right))
            return true;
        else return false; 
    }
};
