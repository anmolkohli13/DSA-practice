vector<int> reverseLevelOrder(Node *root)
{
    // code here
    
    vector<int> arr;
    Node *curr = root;
        
        if(root==NULL){
            return arr;
            
        }
        
        stack<int> st;
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(curr->right)
            {
                q.push(curr->right);
            }
            if(curr->left)
            {
                q.push(curr->left);
            }
            st.push(curr->data);
        }        
        while(!st.empty())
        {
            int temp = st.top();
            arr.push_back(temp);
            st.pop();
        }
        
        
        return arr;   
    
}
