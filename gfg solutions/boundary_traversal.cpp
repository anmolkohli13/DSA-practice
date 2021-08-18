* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void leafnodes(Node *root,vector<int>&v){
        if(root==NULL)
        return ;
        
        leafnodes(root->left,v);
        if(root->left==NULL && root->right==NULL)
        v.push_back(root->data);
        leafnodes(root->right,v);
    }

    void lb(Node*root,vector<int>&v){
        
        if(root==NULL)
        return ;
        
        if(root->left!=NULL || root->right!=NULL) //not leaf node
        v.push_back(root->data);
        
        if(root->left!=NULL) lb(root->left,v);
        else if(root->right!=NULL) lb(root->right,v);

    }

    void rb(Node*root,vector<int>&v){
        
        if(root==NULL)
        return ;
        
        if(root->right) rb(root->right,v);
        else if(root->left) rb(root->left,v);
        
        if(root->left!=NULL || root->right!=NULL) //not leaf node
        v.push_back(root->data);

    }

    vector <int> printBoundary(Node *root)
    {
        vector<int>v;
        if(root==NULL)
        return v;
        
        v.push_back(root->data);
        if(root->left==NULL && root->right==NULL)
        return v;
        
        lb(root->left,v);
        leafnodes(root,v);
        rb(root->right,v);
        
        return v;
    }


};
