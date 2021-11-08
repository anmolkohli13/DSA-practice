class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        int visited[V] = {0};
        
        // ans.push_back(0);
        visited[0] = 1;
        
        queue<int>q;
        q.push(0);
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int j : adj[u])
            {
                if(visited[j] == 0)
                {
                    q.push(j);
                    visited[j] = 1;
                }
            }
            
        }
        return ans;
        
    }
};
