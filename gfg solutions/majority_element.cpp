class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        
        // your code here
        
        int count = 0;
        int candidate = 0;
        
        for(int i = 0; i < size; i++)
        {
            if(count == 0)
            {
                candidate = arr[i];
            }
            if(arr[i] == candidate)
            count++;
            else count--;
            
        }
        
        int c = 0;
        
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == candidate)
            c++;
        }
        if(c > size/2)
        return candidate;
        
        return -1;
    }
};
