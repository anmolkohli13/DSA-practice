class Solution{
public:
    int nCr(int n, int r){
        // code here
        vector<vector<int>> dp(n + 1, vector<int> (r + 1, 0));
            
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= r; j++)
            {
                if(j == 0 || i == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
                }
            }
        }
        
        return dp[n][r];
        //nCr = (n-1)C(r-1) + (n-1)Cr (can be used as rec formula)
        // dp[n][r] = dp[n-1][r-1] + dp[n-1][r]
        
    }
};
