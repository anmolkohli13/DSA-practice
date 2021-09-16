class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        
        int n = N, k = K;
        
        sort(candies,candies+n);
        
        int max=0,min=0;
        vector<int>ans;
        
        for(int i = 0; i < n; i++)
        {
            min+=candies[i];
            n-=k;
        }
        ans.push_back(min);
        n=N;
        int j = 0; 
        for(int i = n-1; i >= j; i--)
        {
            max += candies[i];
            j+=k;
        }
        ans.push_back(max);
        
        return ans;
    }
};
