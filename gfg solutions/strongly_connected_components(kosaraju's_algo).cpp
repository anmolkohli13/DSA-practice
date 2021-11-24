class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
    }
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    // cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
    int kosaraju(int n, vector<int> adj[])
    {
        stack<int> st;
    	vector<int> vis(n, 0); 
    	for(int i = 0;i<n;i++) {
    	    if(!vis[i]) {
    	        dfs(i, st, vis, adj); 
    	    }
    	} 
    	vector<int> transpose[n]; 
    	
    	for(int i = 0;i<n;i++) {
    	    vis[i] = 0; 
    	    for(auto it: adj[i]) {
    	        transpose[it].push_back(i); 
    	    }
    	}
    	int ans = 0;
    	while(!st.empty()) {
    	    int node = st.top();
    	    st.pop(); 
    	    if(!vis[node]) {
    	        ans++;
    	        revDfs(node, vis, transpose); 
    	       // cout << endl; 
    	    }
    	}
    	return ans;
    }
};
