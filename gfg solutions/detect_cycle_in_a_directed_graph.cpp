class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int node,vector<int> adj[], vector<bool>&vis, vector<bool>&dfsvis)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(checkCycle(it,adj,vis,dfsvis))
                return true;
            }
            else if(dfsvis[it])
            return true;
        }
        dfsvis[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<bool> vis(V, false);
        vector<bool> dfsvis(V, false);
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i,adj,vis,dfsvis))
                return true;
            }
        }
        return false;
    }
};
