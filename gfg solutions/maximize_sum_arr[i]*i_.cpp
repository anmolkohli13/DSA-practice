class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        
        int modulo = 1000000007;
        long long sum = 0;
        sort(a,a+n);
        
        for(long long i = 0; i < n; i++)
        {
            sum += i*a[i];    
        }
        return sum%modulo;
        
    }
};
