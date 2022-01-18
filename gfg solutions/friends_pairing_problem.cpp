class Solution
{
    
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        int mod=1e9+7;
        vector<long long>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(long long i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1]+(i-1)*dp[i-2])%mod;
        }
        return dp[n];
    }
};
