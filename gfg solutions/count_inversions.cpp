class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long low,long long mid,long long high)
{
    long long n1 = mid-low+1;
    long long n2 = high-mid;
    
    long long right[n1],left[n2];
    
    for(long long i = 0; i < n1; i++)
    {
        left[i] = arr[low+i];
    }
    for(long long i = 0; i < n2; i++)
    {
        right[i] = arr[mid+i+1];
    }
    
    long long i = 0,j = 0,k = low;
    long long ans = 0;
    
    while(i < n1 && j < n2)
    {
    
        if(left[i] <= right[j])
        arr[k++] = left[i++];
        
        else
        {
            arr[k++] = right[j++];
            ans += (n1-i);
        }
    }
    
    while(i < n1)
    arr[k++] = left[i++];
    
    while(j < n2)
    arr[k++] = right[j++];
    
    return ans;
}

long long mergeSort(long long arr[],long long low,long long high)
{
    long long ans = 0;
    if(low < high)
    {
        long long mid = (low+high)/2;
        
        ans += mergeSort(arr,low,mid);
        ans += mergeSort(arr,mid+1,high);
        
        ans += merge(arr,low,mid,high);
        
    }
    return ans;
}


long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    
    return mergeSort(arr,0,N-1);
}


};
