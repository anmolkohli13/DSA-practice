class Solution {
public:
//     int longestPalindromeSubseq(string S) {
        
//         int n=S.length();
//     vector<vector<int>>arr(n,vector<int>(n,0));
   
//     int len=0;
//     int start=0;
//     int end=0;
   
//     for(int g=0;g<n;g++)
//     {
        
//         for(int i=0,j=g;j<n;i++,j++)
//         {
//             //int flag=0;
//             if(g==0)
//             {
//                 arr[i][j]=1;
               
                    
//             }
            
//             else if(g==1)
//             {
//                 if(S[i]==S[j])
//                     arr[i][j] = 2;
//                 else
//                     arr[i][j] = 1;
//             }
            
//             else{
//                     if(S[i]==S[j])
//                         arr[i][j]=arr[i+1][j-1] + 2;
//                     else 
//                     {
//                         arr[i][j] = max(arr[i][j-1] , arr[i+1][j]);
//                     }
//                 }
//             // if(arr[i][j]>len)
//             // {
//             //     len=arr[i][j];
//             //     start=i;
//             //     end=j;
//             // }
                
        
//         }
//     }
    
//     // for(int i=0;i<n;i++)
//     // {
//     //     for(int j=0;j<n;j++)
//     //     {
//     //         cout<<arr[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
     
    
// //     for(int i=0;i<n;i++)
// //     {
// //         for(int j=0;j<n;j++)
// //         {
            
// //         }
// //     }
    
//     return arr[0][n-1];
        
//     }
    int lcs(int n, string S, string rev)
    {
        vector<vector<int>>arr(n+1,vector<int>(n+1));
        
        for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0|| j== 0)
                    arr[i][j] = 0;
                else if(S[i-1] == rev[j-1])
                    arr[i][j] = arr[i-1][j-1]+1;
                else
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
        return arr[n][n];
    }
    int longestPalindromeSubseq(string S) {
    
        string rev = S;
        reverse(S.begin(),S.end());
        return lcs(S.length(),S,rev);
        
    }
};
