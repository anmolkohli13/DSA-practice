class Solution{
    public:
    void DFSRec(vector<int> adj[], int u, stack<int> &st, vector<bool> &visited)
    {
        visited[u] = true;
        
        for(auto v: adj[u])
        {
            if(visited[v] == false)
            {
                DFSRec(adj, v, st, visited);
            }
        }
        
        st.push(u);
    }
    string topologicalSort(vector<int> adj[],int V)
    {
        stack<int>st;
	    vector<bool>vis(V,false);
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(adj[i].size())
	        {
	           for(auto u :adj[i])
	           {
	               if(vis[u] == false)
	               DFSRec(adj,u,st,vis);
	           }
	        }
	    }
	    string res;
    while(st.empty() == false)
    {
        res += st.top() + 'a';;
        
        st.pop();
    }
    
    return res;
	    
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        
        for(int i = 0; i < N-1; i++)
        {
            string word1 = dict[i];
            string word2 = dict[i+1];
            
            for(int j = 0; j < min(word1.size(),word2.size()); j++)
            {
                if(word1[j] != word2[j])
                {
                    int index1 = word1[j]-'a';
                    int index2 = word2[j]-'a';
                    
                    adj[index1].push_back(index2);
                    break;
                }
            }
        }
        return topologicalSort(adj,K);
    }
};
