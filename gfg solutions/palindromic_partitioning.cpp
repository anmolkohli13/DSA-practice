class Solution{
public:
    int dp[501][501];
    bool isPalindrome(string &str,int i, int j)
    {
        while(i < j)
        {
            if(str[i] != str[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &str, int i, int j)
    {
        if(i >= j )
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        if(isPalindrome(str,i,j) == true)
        return 0;
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j-1; k++)
        {
            int temp = solve(str,i,k) + solve(str,k+1,j) + 1;
            ans = min(temp,ans);
        }
        return dp[i][j] = ans;
    }

    int palindromicPartition(string str)
    {
        int i = 0, j = str.length()-1;
        memset(dp,-1,sizeof(dp));
        
        return solve(str,i,j);
        
    }
};
