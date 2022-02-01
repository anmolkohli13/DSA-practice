class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        int res = 0;
        
        int dp[N] = {0};
        
        for(int i = 0; i < N; i++)
        {
            dp[i] = 1;
            
            for(int j = 0; j < i; j++)
            {
                if(abs(A[j] - A[i]) == 1)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};
