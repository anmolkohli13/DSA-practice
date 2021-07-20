class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        for(int i = 0; i < N; i++)
        {
            arr[i] -= 1;
        }
        
        sort(arr.begin(), arr.end());
        
        int index = N;
    	for(int i = 0 ; i < N ; i++)
    	{
    	   if(arr[i] >= N)
    	   {
    	       arr[i] = 0;
    	       
    	       if(index == N)
    	       {
    	           index = i;
    	       }
    	   }
    	}
        
        for(int i = 0; i < index; i++)
        {
            arr[arr[i] % N] += N; 
        }
        
        for(int i = 0; i < N; i++)
        {
            arr[i] = arr[i] / N;
        }
    }
};

// N = 5, P = 5
// arr[] = {2, 3, 2, 3, 5}

// STEP 1 - (arr[i] -= 1)
// arr[] = {1, 2, 1, 2, 4}

// STEP 2 - (Sorting)
// arr[] = {1, 1, 2, 2, 4}

// STEP 3
// arr[] = {1, 1, 2, 2, 4}
// index = 5

// STEP 4 - (arr[arr[i] % N] += N) [range => 0 -> index - 1]

// index = 0 ->
// arr[] = {1, 6, 2, 2, 4}

// index = 1 ->
// arr[] = {1, 11, 2, 2, 4}

// index = 2 ->
// arr[] = {1, 11, 7, 2, 4}

// index = 3 ->
// arr[] = {1, 11, 12, 2, 4}

// index = 4 ->
// arr[] = {1, 11, 12, 2, 9}

// STEP 5 - (arr[i] = arr[i] / N) [range => 0 -> N - 1]
// arr[] = {0, 2, 2, 0, 1}
