class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&arr)
	{
	    // Code here
	    int N = arr.size();
	    pair<int, int> arrPos[N]; 
    for (int i = 0; i < N; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    }
    
    sort(arrPos, arrPos + N); 
    
    vector<bool> visited(N, false); 
    
    int ans = 0;
    
    for(int i = 0; i < N; i++)
    {
        if (visited[i] == true || arrPos[i].second == i) 
        {
            continue;
        }
        
        int cycle_size = 0; 
        int j = i; 
        
        while (!visited[j]) 
        { 
            visited[j] = 1; 
            
            j = arrPos[j].second; 
            cycle_size++; 
        } 
        
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    }
    
    return ans;
	}
};
