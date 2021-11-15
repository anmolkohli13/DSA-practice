class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void findTopoSort(int node, vector<bool>&vis, stack<int>&st, vector<int>adj[])
	{
	    vis[node] = true;
	    
	    for(auto it: adj[node])
	    if(!vis[it])
	    findTopoSort(it,vis,st,adj);
	    
	    st.push(node);
	    
	}
	
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	   // stack<int>st;
	   // vector<bool>vis(V,false);
	    
	   // for(int i = 0; i < V; i++)
	   // {
	   //     if(!vis[i])
	   //     findTopoSort(i,vis,st,adj);
	   // }
	   // vector<int>topo;
	   // while(!st.empty())
	   // {
	   //     topo.push_back(st.top());
	   //     st.pop();
	   // }
	   // return topo;
	   queue<int> q; 
	    vector<int> indegree(V); 
	    for(int i = 0;i<V;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<V;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	    
	}
};
