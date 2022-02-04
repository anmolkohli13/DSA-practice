class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){

        int dp[n][m];
        
        int ans = INT_MIN;
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(i == n-1 || j == m-1)
                {
                    dp[i][j] = mat[i][j];
                }
                else
                {
                    if(mat[i][j] == 0)
                    dp[i][j] = 0;
                    else
                    {
                        dp[i][j] = min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1])) + 1;
                    }
                }
                ans = max(ans,dp[i][j]);
            }
            
        }
        return ans;
    }
};
