class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string S)
    {
        
       //Your code here
       
        long long int n=S.length();
        vector<vector<long long int>>arr(n,vector<long long int>(n,0));
        long long int num = pow(10,9) + 7;
       
        for(int g=0;g<n;g++)
        {
            
            for(int i=0,j=g;j<n;i++,j++)
            {
                int flag=0;
                if(g==0)
                {
                    arr[i][j]=1;
                    
                }
                
                else if(g==1)
                {
                    if(S[i]==S[j])
                    {
                        arr[i][j]=3;
                    }
                    else
                    arr[i][j] = 2;
                    
                }
                
                else{
                        if(S[i]==S[j])
                        {
                            arr[i][j] = (arr[i+1][j] + arr[i][j-1] + 1) % num;
        
                        }
                            
                        else arr[i][j] = ((arr[i][j-1] + arr[i+1][j] - arr[i+1][j-1])%num + num)%num;
                    }
                    
            
            }
        }
       
       
       
       return arr[0][n-1];
       
    }
     
};
