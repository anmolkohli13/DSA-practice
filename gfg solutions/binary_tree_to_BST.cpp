class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void store(Node *root,vector<int>&vec)
    {
        if(root==NULL)
        return;
        store(root->left,vec);
        vec.push_back(root->data);
        store(root->right,vec);
    }
    void update(Node*root,vector<int>vec,int &idx)
    {
        if(root == NULL)
        return;
        
        update(root->left,vec,idx);
        root->data = vec[idx++];
        update(root->right,vec,idx);
        
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        
        if(root == NULL)
        return root;
        
        vector<int>vec;
        store(root,vec);
        int idx = 0;
        sort(vec.begin(),vec.end());
        update(root,vec,idx);
        return root;
    }
};
