class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    
	    int dp[M+1][V+1];
	    
	    for(int i = 1; i < V+1; i++)
	    dp[0][i] = INT_MAX-1;
	    
	    for(int j = 0; j < M+1; j++)
	    dp[j][0] = 0;
	    
	    for(int j = 1; j <= V; j++)
	    {
            if(j%coins[0] == 0)
            {
                dp[1][j] = (j/coins[0]);
            }
            else
            {
                dp[1][j] = INT_MAX-1;
            }
        }
	    
	    for(int i = 2; i < M+1; i++)
	    {
	        for(int j = 1; j < V+1; j++)
	        {
	            if(coins[i-1] <= j)
	            {
	                dp[i][j] = min((1 + dp[i][j-coins[i-1]]) , dp[i-1][j] );
	            }
	            else
	            dp[i][j] = dp[i-1][j];
	        }
	    }
	    if(dp[M][V] >= INT_MAX-1)
	    return -1;
	    else
	    return dp[M][V];
	} 
	  
};
