class Solution{
public:
    int maximumPath(int n, vector<vector<int>> arr)
    {
        // code here
        
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        int ans = 0;
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == n-1)
                {
                    dp[i][j] = arr[i][j];
                }
                else if(j == 0)
                {
                    dp[i][j] = arr[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
                }
                else if(j == n-1)
                {
                    dp[i][j] = arr[i][j] + max(dp[i+1][j],dp[i+1][j-1]);
                }
                else
                {
                    dp[i][j] = arr[i][j] + max(dp[i+1][j],max(dp[i+1][j+1],dp[i+1][j-1]));
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
