class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll count = 0;
        unordered_map<int,int>mp;
        int sum = 0;
        int i = -1;
        mp[0]=1;
        
        for(i = 0; i < n; i++)
        {
            
            sum+=arr[i];
            if(mp.find(sum) != mp.end())
            {
                count += mp[sum];
                mp[sum]++;
            }
            else{
                mp[sum]++;
            }
        }
        
        return count;
    }
};
