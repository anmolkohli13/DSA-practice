
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* buildTreeHelper(int preorder[], int inorder[], int inS, int inE, int preS, int preE)
    {
        if(preS > preE)
        return NULL;
        
        int rootdata = preorder[preS];
        Node *root = new Node(rootdata);
        //root -> data = rootdata;
        int rootindex = -1;
        
        for(int i = 0; i <= inE; ++i)
        {
            if(inorder[i] == rootdata)
            {
                rootindex = i;
                break;
            }
        }
        //left subtree
        int LpreS = preS + 1, LinS = inS;
        int LinE = rootindex - 1;
        int LpreE = (LinE - LinS) + LpreS;
        
        //right subtree
        int RpreS = LpreE + 1;
        int RpreE = preE;
        int RinS = rootindex + 1;
        int RinE = inE;
        
        Node* leftTree = buildTreeHelper(preorder, inorder, LinS, LinE, LpreS, LpreE);
        
        Node* rightTree = buildTreeHelper(preorder, inorder, RinS, RinE, RpreS, RpreE);
        root -> left = leftTree;
        root -> right = rightTree;
        return root;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return buildTreeHelper(pre, in, 0, n-1, 0, n-1);
    }
};
