class Solution{

	public:
	int prefixStrings(int N)
	{
	    
	    long long dp[N+1];
		memset(dp, 0, sizeof dp);

		int mod = (int)(1e9 + 7);

		dp[0] = dp[1] = 1;
 
	    for (int i = 2; i <= N; i++)
	    {
	        dp[i] = 0;
	        for (int j = 0; j < i; j++)
	            dp[i] =(dp[i]%mod + (dp[j]%mod * dp[i-j-1]%mod)%mod)%mod;
	    }

	    return (int)(dp[N]);

	}

};
