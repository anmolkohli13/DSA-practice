class Solution{
		

	public:
	int lcs(int n, int m, string text1, string text2)
    {
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
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length(), m = str2.length();
	    int sub = lcs(n,m,str1,str2);
	    int ins = n-sub;
	    int del = m-sub;
	    return ins+del;
	    
	} 
};
