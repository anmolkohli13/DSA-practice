class Solution {
public:
    int search(vector<int>& arr, int target) {
     
        int  low=0,high=arr.size()-1;
        
        while(low <= high)
        {
            int mid = (low+high) >> 1;
            
            if(arr[mid] == target)
            {
                return mid;
            }
            
            if(arr[low] <= arr[mid]) //checking if the left half from mid is sorted
            {
                if(arr[low] <= target && target <= arr[mid])  //if target lies in the left sorted part from mid
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            else //checking if the right half from mid is sorted
            {
                if(arr[mid] <= target && target <= arr[high])  //if target lies in the right sorted part from mid
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            
        }
        return -1;
    }
};
