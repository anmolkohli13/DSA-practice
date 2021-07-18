class Solution{
    public:
    bool match(string pattern, string wild)
    {
        // code here
        
        int n = pattern.length();
        int m = wild.length();
        
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        
        for(int i = dp.size()-1; i >= 0; i--)
        {
            for(int j = dp[0].size()-1; j >= 0; j--)
            {
                if(i == dp.size()-1 && j == dp[0].size()-1)
                    dp[i][j] = true;
                
                else if(i == dp.size()-1)
                    dp[i][j] = false;   
                
                else if(j == dp[0].size()-1)
                {
                    if(pattern[i] == '*')
                        dp[i][j] = dp[i+1][j];
                
                    else
                        dp[i][j] = false;
                    
                }
                else
                {
                    if(pattern[i] == '?')
                    dp[i][j] = dp[i+1][j+1];
                    
                    else if(pattern[i] == '*')
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    
                    else if(pattern[i] == wild[j])
                    dp[i][j] = dp[i+1][j+1];
                    
                    else
                    dp[i][j] = false;
                    
                }
            }
        }
        // for(int i = 0; i < dp.size()-1; i++)
        // {
        //     for(int j = 0; j < dp[0].size()-1; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //cout<<dp[n-1][m-1]<<endl;
        return dp[0][0];
        
    }
};
