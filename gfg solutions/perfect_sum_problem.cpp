class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int dp[n+1][sum+1];
        
        for(int i = 0; i < sum+1; i++)
        dp[0][i] = 0;
        
        for(int j = 0; j < n+1; j++)
        dp[j][0] = 1;
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 1; j < sum+1; j++)
            {
                if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                
                else 
                dp[i][j] = dp[i-1][j];
                
                cout<<dp[i][j]<<" ";
                
            }
            cout<<endl;
        }
        
        return dp[n][sum];
	}
	  
};
