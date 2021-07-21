class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here     
        
        // thought of the same logic about finding the zeros and then calculating with condition of zero
        
        long long int left = nums[0],right=nums[nums.size()-1];
        vector<long long int>ans (nums.size(),1);
        for(int i = 1; i < nums.size(); i++)
        {
            ans[i] = left;
            left *= nums[i];   // multiplying all the elements of the left of the element at the index i
        }
        for(int i = nums.size()-2; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];   // multiplying all the elements of the left of the element at the index i
        }
        return ans;
        
    }
};
