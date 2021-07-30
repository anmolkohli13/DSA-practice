class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        // read the question carefully as it is written each element represents the MAX steps which can be taken
        
         int jumps=0,currend=0,currfar=0;
        for(int i=0;i<n-1;i++)
        {
            currfar = max(currfar,i+arr[i]);
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
        
    }
};
