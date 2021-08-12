long long maxProduct(int *arr, int n) {
	    // code here
	    
	    long long int maxi,mini,prod;
	    int i;
	    
	    maxi = mini = prod = 1;
	    
	    for(i = 0; i < n; i++)
	    {
	        if(arr[i] > 0)
	        {
	            maxi *= arr[i];
	        }
	        
	        
	        else if(arr[i] == 0)
	        {
	            continue;
	        }
	        
	        else
	        {
	            mini *= arr[i];
	        }
	        prod *= arr[i];
	        
	        
	    }
	    
	    if(arr[i-1] == 0 && (maxi == 1 && mini == 1) )
	        maxi = mini = 0;
	    
	    long long int res = std::max(mini,maxi);
	    res = std::max(res,prod);
	    
	    return res;
	}