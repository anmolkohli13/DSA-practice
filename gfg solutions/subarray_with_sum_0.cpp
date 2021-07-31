class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        
        int temp[n];
        temp[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            temp[i] = temp[i-1]+arr[i];
        }
        
        unordered_map<int,int>mp;
        
        for(int i = 0; i < n; i++)
            mp[temp[i]]++;
        
        // for(int i = 0; i < mp.size(); i++)
        // {
        //     if(mp[i] > 1 || mp[i] == 0)
        //     return true;
        // }
        unordered_map<int, int>:: iterator itr;
        for(itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(itr->second > 1 || itr->first == 0)
            return true;
        }
        
        return false;
        
        
    }
};
