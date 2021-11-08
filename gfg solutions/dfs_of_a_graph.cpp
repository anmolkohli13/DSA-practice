class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void DFSUtil(vector<int>adj[],int curr,vector<bool>&visited,vector<int>&ans)
    {
        ans.push_back(curr);
        visited[curr] = true;
        for(auto x : adj[curr])
        {
            if(visited[x] == false)
            DFSUtil(adj,x,visited,ans);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        vector<bool>visited(V,false);
        
        for(int i = 0; i < V; i++)
        {
            if(visited[i] == false)
            {
                DFSUtil(adj,i,visited,ans);
            }
        }        
        return ans;
        
    }
};
