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
    
    void InOrder(TreeNode *root, int k, int &index, int &res)
    {
        if(root != NULL)
        {
            InOrder(root->left, k, index, res);
            
            if(index == k)
            {
                res = root->val;
            }
            index++;
            
            InOrder(root->right, k, index, res);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int index = 1;
        int res = -1;
        
        InOrder(root, k, index, res);
        
        return res;
    }
};
