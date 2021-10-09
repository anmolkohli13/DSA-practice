class Solution{
public:
//     bool getPartition (int arr[],int n,int sum) {
//       // cout<<sum<<endl;
//       if(sum == 0) {
//           return true;
//       } 
//       else if(sum < 0 || n <= 0) {
//           return false;
//       } 
       
//       else if(arr[n-1] > sum) {
//           return getPartition(arr,n - 1,sum);
//       }
//       return ( getPartition(arr,n - 1,sum - arr[n-1]) or getPartition(arr,n - 1,sum));
//   }
   
//   int equalPartition(int n, int arr[])
//   {
//       // code here
//       int sum = 0;
//       for(int i = 0; i < n; i++) {
//           sum += arr[i];
//       }
       
//       if(sum % 2 == 0 ) {
//           return getPartition(arr,n,sum/2);
//       }
//       return false;
//   }
bool isSubset(int N, int arr[], int sum)
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
   
   int equalPartition(int N, int arr[])
   {
       int sum = 0;
       for(int i = 0; i < N; i++)
            sum += arr[i];
       
       if(sum % 2 != 0)
          return false;
       
       return isSubset(N, arr, sum/2);
   }
};
