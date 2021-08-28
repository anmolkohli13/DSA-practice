/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree
    
    unordered_map<string,int> mp;
     vector<Node*>ans;

string helper(Node *root)
    {
        
        if(!root)
        {
            return "";
        }
        string s ="#";
        s += helper(root->left);
        s += to_string(root->data);
        s += helper(root->right);
        s += "#";
        mp[s]++;
        if(mp[s]==2){
            ans.push_back(root);
        }
        return s;
    }



vector<Node*> printAllDups(Node* root)
{
    // Code here
    mp.clear();
    ans.clear();
    helper(root);
    return ans;
    
}
