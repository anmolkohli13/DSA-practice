/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    
    void InOrder(Node *root, int k, int &index, int &res)
    {
        if(root != NULL)
        {
            InOrder(root->left, k, index, res);
            
            if(index == k)
            {
                res = root->data;
            }
            index++;
            
            InOrder(root->right, k, index, res);
        }
    }
    
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        int index = 1;
        int res = -1;
        
        InOrder(root, K, index, res);
        
        return res;
    }
};
