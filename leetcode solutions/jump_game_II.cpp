class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps=0,currend=0,currfar=0,n=nums.size();
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
        if(currend < n-1) return -1;
        return jumps;
        
//         int n = nums.size();
        
//         if(n<2)return 0;
// 	 int level=0,currentMax=0,i=0,nextMax=0;

// 	 while(currentMax-i+1>0){		//nodes count of current level>0
// 		 level++;
// 		 for(;i<=currentMax;i++){	//traverse current level , and update the max reach of next level
// 			nextMax=max(nextMax,nums[i]+i);
// 			if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level 
// 		 }
// 		 currentMax=nextMax;
// 	 }
// 	 return 0;
        
    }
};
