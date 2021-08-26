/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int LSS(TreeNode<int> *root,int &ans)
{
    if(root == NULL)
        return 0;
    
    int curr_sum = root->data + LSS(root->left,ans)+LSS(root->right,ans);
    
    ans = max(curr_sum,ans);
    
    return curr_sum;
    
}

int largestSubtreeSum(TreeNode<int> *root) {
	// Write your code here.
    
    if(root==NULL)
    {
        return 0;
    }
    int ans = -32767;
    
    LSS(root,ans);
    
    return ans;
    
    
}
