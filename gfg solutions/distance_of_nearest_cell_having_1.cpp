class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> res( n ,vector<int> ( m , INT_MAX));
	    
	    queue<pair<int,int>> q;
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j< m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                q.push({i,j});
	                res[i][j] = 0;
	            }
	        }
	    }
	    vector<pair<int,int>> moves = {{0 , 1}, {1 , 0}, {0 , -1}, {-1 , 0}};
	    
	    while(!q.empty())
        {
            int nx = q.front().first;
            int ny= q.front().second;
            
            q.pop();
            
            for(auto move:moves)
            {
                int x = nx + move.first;
                int y = ny + move.second;
                
                if(x >= 0 and x < n and y >= 0 and y < m)
                {
                    if(res[x][y] > res[nx][ny] + 1)
                    {
                        res[x][y] = res[nx][ny] + 1;
                        
                        q.push({x, y});
                    }
                }
            }
        }
	    return res;
	    
	}
};
