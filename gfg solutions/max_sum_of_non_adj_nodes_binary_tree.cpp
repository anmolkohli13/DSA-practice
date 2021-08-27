/************************************************************

    Following is the TreeNode class structure

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

pair<int,int>maxSumHelper(TreeNode<int>*root)
{
    if(root == NULL)
    {
        pair<int,int>sum(0,0);
        return sum;
    }
    pair<int,int>sum1 = maxSumHelper(root->left);
    pair<int,int>sum2 = maxSumHelper(root->right);
    pair<int,int>sum;
    
    sum.first = sum1.second + sum2.second + root->data;
    sum.second = max(sum1.first,sum1.second) + max(sum2.first,sum2.second);
    
    return sum;
    
    
}


int maximumSumOfNodes(TreeNode<int> *root)
{
	//    Write your code here
    
    pair<int,int>res = maxSumHelper(root);
    return max(res.first,res.second);
    
    
}
