class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int i,n=nums.size();
        //cout<<n;
        int* hs= new int [n];
        for(i=0;i<n;i++)
            hs[i]=0;
        
        for(i=0;i<n;i++)
        {
            hs[nums[i]]+=1;
        }
        for(i=0;i<n;i++)
        {
            if(hs[i]>1)
                return i;
        }
        return 0;
        }
};