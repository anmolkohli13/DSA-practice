class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size(),cnt = 0, tot = 0, days = 0;
        queue<pair<int,int>>rotten;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                    tot++;
                if(grid[i][j] == 2)
                    rotten.push({i,j});
            }
        }
        
        int dx[4] = {0 , 0 , 1 , -1};
        int dy[4] = {1 , -1 , 0 , 0};
        
        while(!rotten.empty())
        {
            int k = rotten.size();
            cnt += k;
            while(k--)
            {
                int x = rotten.front().first , y = rotten.front().second;
                rotten.pop();
                
                for(int i = 0; i < 4; i++)
                {
                    int cx = x + dx[i];
                    int cy = y + dy[i];
                    if(cx < 0 || cy < 0 || cy >= n || cx >= m || grid[cx][cy] !=1)continue;
                    
                    grid[cx][cy] = 2;
                    rotten.push({cx,cy});                    
                }                
            }
            if(!rotten.empty())
                days++;
            
        }
        return tot == cnt ? days:-1;
        
        
    }
};
