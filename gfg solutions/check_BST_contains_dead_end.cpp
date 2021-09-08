/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

bool solve(Node *root, int min, int max)
{
    if(root == NULL)
    return false;
    
    if(max == 1 || max == min)
    return true;
    
    return solve(root->left,min,root->data-1) || solve(root->right,root->data+1,max);
}


bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root,INT_MIN,INT_MAX);
    
}
