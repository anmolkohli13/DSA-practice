class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n+1][m+1];
     memset(dp,0,sizeof(dp));
     int i,j;
     for(j=m-1;j>=0;j--)
     {
         for(i=n-1;i>=0;i--)
         {
             if(i==0)
             {
                 dp[i][j]=M[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
             }
             else if(j==m-1)
             {
                 dp[i][j]=M[i][j];
             }
             else if(i==n-1)
             {
                 dp[i][j]=M[i][j]+max(dp[i-1][j+1],dp[i][j+1]);
             }
             else
             {
                 dp[i][j]=M[i][j]+max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]));
             }
         }
       }
       
       int max=dp[0][0];
       for(int k=1;k<n;k++)
       {
           if(dp[k][0]>max)
           {
               max=dp[k][0];
           }
       }
       return max;
   
    }
};
