class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        int jumps=0,currend=0,currfar=0;
        for(int i=0;i<n-1;i++)
        {
            currfar = max(currfar,i+nums[i]);
            if(i==currend)
            {
                jumps++;
                currend=currfar;
            }
            if(currend >= n-1)
            break;
        }
        if(currend < n-1) return false;
        return true;
        
        
    }
};
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
        
//         int i = 0,n=nums.size();
//     for (int reach = 0; i < n && i <= reach; ++i)
//         reach = max(i + nums[i], reach);
//     return i == n;
        
        
//     }
// };
