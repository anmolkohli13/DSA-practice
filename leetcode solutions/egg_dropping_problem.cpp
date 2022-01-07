class Solution {
public:
    int dp[101][10001];
    int solve(int eggs, int floors)
    {
        
        if(floors == 1 || floors == 0)
            return floors;
        
        if(eggs == 1)
            return floors;
        
        if(dp[eggs][floors] != -1)
            return dp[eggs][floors];
        
        int ans = INT_MAX-1, l = 1, h = floors, temp = 0;
        while(l<=h)
                {
                    int mid=(l+h)/2;
                    int left = solve(eggs-1,mid-1);   //egg broken check for down floors of mid
                    int right = solve(eggs,floors-mid) ;   // not broken check for up floors of mid
                    temp = 1+max(left,right);          //store max of both 
                    if(left<right){                  //since right is more than left and we need more in worst case 
                      l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward 
                    {    
                        h=mid-1;
                    }
                    ans=min(ans,temp);               //store minimum attempts
                }        
        return dp[eggs][floors] = ans;
        
            
    }
    
    
    int superEggDrop(int k, int n) {
        
        memset(dp,-1,sizeof(dp));
        return solve(k,n);     
        
    }
};
