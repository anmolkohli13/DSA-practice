class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
        map<int,int> m;
        queue<pair<Node*,int>>q;
        vector<int>vec;
        
        if(!root) return vec;
        q.push({root,0});
        
        while(!q.empty())
        {
            Node *t = q.front().first;
            int h = q.front().second;
            q.pop();
            if(!m[h]) m[h] = t->data;
            if(t->left) q.push({t->left,h-1});
            if(t->right) q.push({t->right,h+1});
            
        }
        
        for(auto x: m)
        vec.push_back(x.second);
        
        return vec;
        
    }

};
