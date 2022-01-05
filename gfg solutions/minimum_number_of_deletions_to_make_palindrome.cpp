int lps(string str,int n)
{
    string rev = str;
    reverse(str.begin(),str.end());
    
    vector<vector<int>>arr(n+1,vector<int>(n+1));
        
        for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0|| j== 0)
                    arr[i][j] = 0;
                else if(str[i-1] == rev[j-1])
                    arr[i][j] = arr[i-1][j-1]+1;
                else
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
        return arr[n][n];
}

int minDeletions(string str, int n) { 
    return n-lps(str,n);
} 
