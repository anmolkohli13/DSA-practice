bool findPair(int arr[], int size, int n){
    //code
    
    // int low=0,high=size-1,mid,i;
    
    // sort(arr,arr+size);
    
    // for(i = size-1; i >= 0; i--)
    // {
    //     int diff = arr[i]-n;
    //         while(low <= high)
    //         {
    //             mid = (low+high)/2;
    //             if(arr[mid] == diff)
    //             {
    //                 return true;
    //             }
                
    //             else if(arr[mid] < diff)
    //             low = mid+1;
                
    //             else
    //             high = mid-1;
                
    //         }
    //     }
        
    
    // return false;
    sort(arr,arr+size);
    bool flag;
    for(int i=size-1;i>=0;i--)
    {
        int x = arr[i] - n;
        flag = binary_search(arr,arr+size,x);
        if(flag == true)
        return flag;
    }
    return flag;
}
