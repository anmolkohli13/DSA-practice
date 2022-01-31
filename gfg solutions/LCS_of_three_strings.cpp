int dp[21][21][21];

int helper(string &A, string &B, string &C, int x, int y, int z)
{
    
    if(x == 0 || y == 0 || z == 0)
        return 0;
        
    if(dp[x][y][z] != -1)
        return dp[x][y][z];
        
    if(A[x-1] == B[y-1] && B[y-1] == C[z-1])
    {
        return dp[x][y][z] = 1+helper(A,B,C,x-1,y-1,z-1);
    }
    else
    {
        return dp[x][y][z] = max(helper(A,B,C,x-1,y,z), max(helper(A,B,C,x,y-1,z),helper(A,B,C,x,y,z-1)));
    }
    return -1;
}

int LCSof3 (string A, string B, string C, int x, int y, int z)
{
    memset(dp,-1,sizeof(dp));
    return helper(A,B,C,x,y,z);
    
}

// int LCSof3(string str1, string str2, string str3, int n1, int n2, int n3)
// {
//     int dp[n1 + 1][n2 + 1][n3 + 1];
    
//     for(int i = 0; i <= n1; i++)
//     {
//         for(int j = 0; j <= n2; j++)
//         {
//             for(int k = 0; k <= n3; k++)
//             {
//                 if(i == 0 || j == 0 || k == 0)
//                 {
//                     dp[i][j][k] = 0;
//                 }
//                 else if(str1[i - 1] == str2[j - 1] and str2[j - 1] == str3[k - 1])
//                 {
//                     dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
//                 }
//                 else
//                 {
//                     dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
//                 }
//             }
//         }
//     }
    
//     return dp[n1][n2][n3];
// }
