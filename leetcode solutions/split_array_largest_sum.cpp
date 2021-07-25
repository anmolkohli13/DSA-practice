class Solution {
public:
    
    int isPossible(vector<int>&nums,int mid,int m)
    {
        
        int cnt = 0; 
        int sumAllocated = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sumAllocated + nums[i] > mid)
            {
                cnt++;
                sumAllocated = nums[i];
                if(sumAllocated > mid)
                    return false;
            }
            else
            {
                sumAllocated += nums[i];
            }
        
        }
        if(cnt < m)
            return true;
        
        return false;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        if(m > nums.size())
            return -1;
        
        int low = nums[0],high = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            high = high + nums[i];
            low = min(low,nums[i]);
        }
        int res = -1;
        
        while(low <= high)
        {
            int mid = (low+high)>>1;
            
            if(isPossible(nums,mid,m))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
                
                
        }
            
        return low;
        
    }
};
