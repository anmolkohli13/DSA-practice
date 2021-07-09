// watch striver's video for the explanation and the intuition

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> nums){
        // code here
        
        //int n = nums.size(),k,l;
        int k,l; 
        
        for(k = N-2; k >= 0; k--)
        {
            if(nums[k] < nums[k+1]){
                break;
            }
        }
        if(k<0){
                reverse(nums.begin(),nums.end());
                }
        else{
            for(l = N-1; l > k; l--){
            if(nums[l] > nums[k]){
            break;
            }
                }
                
                swap(nums[k],nums[l]);
                reverse(nums.begin()+k+1 ,nums.end());
                
            }
            
            return nums;
        }
        
        
    
};
