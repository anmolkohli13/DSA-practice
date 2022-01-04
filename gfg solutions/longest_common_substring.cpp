class Solution{
    public:
    int dp[1001][1001];
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int sol = 0;
        for(int i = 0; i <= n; i++)
		    {
		        for(int  j = 0; j <= m; j++)
		        {
		            if(i == 0 || j == 0)
		            {
		                dp[i][j] = 0;
		            }
		            else
		            {
    		            if(S1[i-1] == S2[j-1])
    		            {
    		                dp[i][j] = dp[i-1][j-1] + 1;
    		            }
    		            else
    		            {
    		                dp[i][j] = 0;
    		            }
		            }
		            sol = max(sol,dp[i][j]);
		        }
		    }
		  
		  return sol;    
        
    }
};
