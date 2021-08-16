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
    
     void rightViewUtil(vector<int>&vec,TreeNode *root, int level,int *max_level)
    {
        //if root is null, we simply return.
        if (root==NULL)  return;
        
        //if this is the first node of its level then it is in the left view.
        if (*max_level < level)
        {
            //storing data of current node in list.
            vec.push_back(root->val);
            *max_level = level;
        }
        
        //calling function recursively for left and right subtrees of current node. 
        
        rightViewUtil(vec,root->right, level+1, max_level);
        rightViewUtil(vec,root->left, level+1, max_level);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        int max_level = 0;
        vector<int> vec;
        rightViewUtil(vec,root, 1, &max_level);
        //returning the list.
        return vec;       
        
    }
};
