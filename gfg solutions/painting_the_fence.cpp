class Solution{
    public:
    long long countWays(int n, int k){
        
        long long mod = 1e9+7;
        
        if(n == 1)
        return k;
        
        if(n == 2)
        return (k+(k*(k-1)));
        
        long long same = 0, diff = 0,total = 0;
        same = k;
        diff = k*(k-1);
        total = (same+diff)%mod;
        
        for(int i = 3; i <= n ; i++)
        {
            same = (diff * 1)%mod;
            diff = (total*(k-1))%mod;
            total = (same+diff)%mod;
        }
        return total%mod;
        
    }
};
