class Solution{
public:
    int dp[101][101];
    public:
    int solve(int arr[],int i, int j)
    {
        if(i >= j)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i; k <= j-1; k++)
        {
            int temp_ans = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            if(temp_ans < ans)
            ans = temp_ans;
        }
        // cout<<ans;
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};
