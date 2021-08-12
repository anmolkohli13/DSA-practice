// same as that of longest common subsequence (LCS) with just the condition i!=j
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
		    
		    vector<vector<int>> arr(n+1, vector<int>(m+1));
		    
		    for(int i = 0; i <= n; i++)
		    {
		        for(int  j = 0; j <= m; j++)
		        {
		            if(i == 0 || j == 0)
		            {
		                arr[i][j] = 0;
		            }
		            else if(text1[i-1] == text2[j-1])
		            {
		                arr[i][j] = arr[i-1][j-1] + 1;
		            }
		            else
		            {
		                arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
		            }
		        }
		    }
		  ;
		  return arr[n][m];
        
        
    }
};