class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        
        // unordered_map<int,int> mp;
        // for(int i = 0; i < n; i++)
        // {
        //     mp[arr[i]]++;
        // }
        // for(int i = 0; i < mp.size(); i++)
        // {
        //     if(mp.find(k-arr[i]))
        // }
        
        int cnt = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(k-arr[i]) != mp.end())
                cnt += mp[k-arr[i]];
                
            mp[arr[i]]++;
        }
        return cnt;
        
    }
};
