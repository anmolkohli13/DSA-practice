class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
     
        int n = arr.size();
         int low = 0, high = n-1, mid;
    int first=-1,second=-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == x)
        {
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] < x)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    low = 0,high=n-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == x)
        {
            second = mid;
            low = mid+1;
        }
        else if(arr[mid] < x)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    vector<int>ans;
    ans.push_back(first);
    ans.push_back(second);
    return ans;
        
    }
};
