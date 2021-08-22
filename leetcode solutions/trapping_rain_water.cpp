class Solution {
public:
    int trap(vector<int>& arr) {
        
        
        int i;
        int n = arr.size();
        int *left = new int[n];
        int *right = new int[n];
        
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        
        for(i = 1; i < n; i++)
        {
            left[i] = max(arr[i],left[i-1]);
        }
        for(i = n-2; i >= 0; i--)
        {
            right[i] = max(arr[i],right[i+1]);
        }
        
        int ans=0;
        
        for(i = 0; i < n; i++)
        {
            ans = ans + (min(left[i],right[i]) - arr[i]); 
        }
        return ans;
        
        
    }
};
