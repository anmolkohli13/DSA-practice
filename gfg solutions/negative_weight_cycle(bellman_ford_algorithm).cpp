class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	    int inf = 10000000;
	    vector<int> dist(n, inf); 
	    dist[0] = 0;
	    
	    
	    for(int i = 1; i <= n-1; i++) {
        for(auto it: edges) {
            if(dist[it[0]] + it[2] < dist[it[1]]) {
                dist[it[1]] = dist[it[0]] + it[2]; 
                }
            }
        }
        int fl = 0; 
        for(auto it: edges) {
            if(dist[it[0]] + it[2] < dist[it[1]]) {
                // cout << "Negative Cycle"; 
                fl = 1; 
                break; 
            }
        }
        return fl;
	    
	    
	}
};
