class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001] = {{0}} ;
    // memset(dp,-1,sizeof(t));
    // dp[0][0] = {{-1}};
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        
        // if(n == 0 || W == 0)
        // return 0;
        
        // if(dp[n][W] != 0)
        // return dp[n][W];
        
        // if(wt[n-1] <= W)
        // {
        //     return dp[n][W] = max( (val[n-1]+knapSack(W-wt[n-1], wt, val, n-1 )) , knapSack(W,wt,val,n-1) );
        // }
        // else if(wt[n-1] > W)
        // return dp[n][W] = knapSack(W,wt,val,n-1);
        
        for(int i = 1; i < n+1; i++)
        for(int j = 1; j < W+1; j++)
        {
            if(wt[i-1] <= j )
            {
                dp[i][j] = max((val[i-1] + dp[i-1][j - wt[i-1]]) , dp[i-1][j] );
            }
            
            else
            dp[i][j] = dp[i-1][j];
            
        }
       return dp[n][W];
       
    }
};
