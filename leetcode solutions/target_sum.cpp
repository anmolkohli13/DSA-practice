class Solution {
public:
    
    int countSubsets(vector<int> arr, int n, int sum)
	{
        // Your code goes here
        
        int dp[n+1][sum+1];
        
        for(int i = 0; i < sum+1; i++)
        dp[0][i] = 0;
        
        for(int j = 0; j < n+1; j++)
        dp[j][0] = 1;
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 0; j < sum+1; j++) //did this change here as we want to include the 0's in the array too (we didn't consider this case earlier and only took into consideration the empty subset case)
            {
                if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                
                else 
                dp[i][j] = dp[i-1][j];
                
                // cout<<dp[i][j]<<" ";
                
            }
            // cout<<endl;
        }
        
        return dp[n][sum];
	}
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];        
        int M = (sum + target)/2;
        if(sum < abs(target) || (sum + target) % 2 != 0) // abs value for covering the cases when target value is given negative
            return 0;
         return countSubsets(nums, nums.size(), M);
        
    }
};
