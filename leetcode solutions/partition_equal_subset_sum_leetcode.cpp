class Solution {
public:
    
    bool isSubset(int N, vector<int>&arr, int sum)
   {
       int t[N+1][sum+1];
       
       for(int i = 0; i < N+1; i++)
       {
           for(int j = 0; j < sum+1; j++)
           {
               if(i == 0)
                 t[i][j] = 0;
               if(j == 0)
                 t[i][j] = 1;
           }
       }
       
       for(int i = 1; i < N+1; i++)
       {
           for(int j = 1; j < sum+1; j++)
           {
               if(arr[i-1] <= j)
               {
                   t[i][j] = t[i-1][j] || t[i-1][j - arr[i-1]];
               }
               else
                  t[i][j] = t[i-1][j];
           }
       }
     return t[N][sum];
   }
    
    
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int N = arr.size();
       for(int i = 0; i < N; i++)
            sum += arr[i];
       
       if(sum % 2 != 0)
          return false;
       
       return isSubset(N, arr, sum/2);
    }
};
