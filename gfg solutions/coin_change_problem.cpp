class Solution {
  public:
    long long int count(int S[], int m, int n) {
        // code here.
        
        long long int dp[m+1][n+1] = {{0}};
        
        for(int i = 0; i < n+1; i++)
        dp[0][i] = 0;
        
        for(int j = 0 ; j < m+1; j++)
        dp[j][0] = 1;
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(S[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
        
    }
};
