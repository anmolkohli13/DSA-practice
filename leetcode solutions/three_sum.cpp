class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        if(n < 3)
            return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n; i++)
        {
            int front = i+1;
            int back = n-1;
            int target = -nums[i];
            
            while(front < back)
            {
                int sum = nums[front]+nums[back];
                
                if(sum < target)
                    front++;
                else if(sum > target)
                    back--;
                else
                {
                    vector<int>temp = {nums[i],nums[front],nums[back]};
                    ans.push_back(temp);
                    
                    while(front < back && nums[front] == temp[1])
                        front++;
                    while(front < back && nums[back] == temp[2])
                        back--;
                        
                }
                
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i])
                i++;
            
        }
        return ans;
        
    }
};
