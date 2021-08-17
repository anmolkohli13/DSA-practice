/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      
        vector<int> arr;
        
        if(node==NULL){
            return arr;
            
        }
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
        
            struct Node* temp = q.front();
            arr.push_back(temp->data);
            q.pop();
            
            if(temp->left!=NULL){
                
                q.push(temp->left);
            }
            
            if(temp->right!=NULL){
                
                q.push(temp->right);
                
            }
        
        }
        
        return arr;
          
    }
};
