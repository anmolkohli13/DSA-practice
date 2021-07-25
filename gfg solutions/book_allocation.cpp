class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    int isPossible(int arr[],int pages,int students,int n)
    {
        int cnt = 0;
        int sumAllocated = 0;
        for(int i = 0; i < n; i++)
        {
            sumAllocated += arr[i];
            if(sumAllocated > pages)
            {
                cnt++;
                sumAllocated = arr[i];\
            }
                if(sumAllocated > pages)
                {
                    return false;
                }
                
        }
        if(cnt < students)
        {
            return true;
        }
        return false;
    }
    
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        
        if(m > n)
        return -1;
        int low = arr[0];
        int high = 0;
        
        for(int i = 0; i < n; i++)
        {
            high = high + arr[i];
            low = min(low,arr[i]);
        }
        
        int res = -1;
        while(low <= high)
        {
            int mid = (low+high) >> 1;
            
            if(isPossible(arr,mid,m,n))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid+1;
            }
            
        }
        //return res;
        return low;
        
        
    }
};
