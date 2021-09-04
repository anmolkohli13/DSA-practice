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
    TreeNode* searchBST(TreeNode* root, int val) {
        
//         if(root == NULL || root->val == val)
//             return root;
        
//         if(root->val > val)
//         {
//             root = searchBST(root->left,val);
//         }
//         else if(root->val < val)
//         {
//            root = searchBST(root->right,val);
//         }
//         // else{
//         //     return root;
//         // }
        
//         return root;
            while (root != nullptr && root->val != val) {
              root = (root->val > val) ? root->left : root->right;
            }
            return root;
    }
};

