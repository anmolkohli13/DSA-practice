
/*Structure of the node of the binary tree is as
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
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code herestruct Node* temp;
    vector<int>vec;
    
    if(root==NULL)
    return vec;
    
    stack <struct Node*> s1;
    stack <struct Node*> s2;
    s1.push(root);
    
    Node *temp;
    
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            temp = s1.top();
            s1.pop();
            vec.push_back(temp->data); 

            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        while(!s2.empty()){
            temp = s2.top();
            s2.pop();
            vec.push_back(temp->data);
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
    }

    }
};
