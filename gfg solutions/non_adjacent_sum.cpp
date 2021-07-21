class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        // int sum1 = 0,sum2 = 0;
        // for(int i = 0; i < n ; i++)
        // {
        //     if(i%2 == 0)
        //     {
        //         sum1 += arr[i];
        //     }
        //     else sum2 += arr[i];
        // }
        // return max(sum1,sum2);
        
        int inc = arr[0];
        int exc = 0;
        
        for(int i = 1; i < n ; i++)
        {
            int ninc = exc+arr[i];
            int nexc = max(inc,exc);
            
            inc = ninc;
            exc = nexc;
        }
        int ans = max(inc,exc);
        return ans;
    }
};
