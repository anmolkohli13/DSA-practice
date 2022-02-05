class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
           sort(arr,arr+N);
           int ans = 0;
           
           for(int i = N-1; i >= 1; i--)
           {
               if( (arr[i]-arr[i-1]) < K)
               {
                   ans+= (arr[i]+arr[i-1]);
                   i--;
               }
           }
           return ans;
    }
};
