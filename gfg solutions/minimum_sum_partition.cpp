class Solution{

  public:
  
    vector<int> subsetSum(int arr[],int n, int sum)
    {
        bool dp[n+1][sum+1];
        
        for(int i = 0; i < sum+1; i++)
        dp[0][i] = false;
        
        for(int j = 0; j < n+1; j++)
        dp[j][0] = true;
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 1; j < sum+1; j++)
            {
                if(arr[i-1] <= j)
               {
                   dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
               }
               else
                  dp[i][j] = dp[i-1][j];
            }
        }
        vector<int>values;
        for(int i = 0; i <= sum/2; i++)
        {
            if(dp[n][i])
            values.push_back(i);
        }
        return values;
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum=0;
	    for(int i = 0; i < n; i++)
	    sum+=arr[i];
	    
	    vector<int> values = subsetSum(arr,n,sum);
	    
	    int mn = INT_MAX;
	    
	    for(int i = 0; i < values.size(); i++)
	    {
	        mn = min(mn,(sum-2*values[i]));         
	    }
	    return mn;
	    
	} 
};
