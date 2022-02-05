class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n = S.length();
	    int arr[n];
	    
	    for(int x = 0; x < n; x++)
	    {
	        if(S[x] == '1')
	        arr[x] = -1;
	        else
	        arr[x] = 1;
	    }
	    
	    int i,csum=arr[0],osum=arr[0];
        
        for(i=1;i<n;i++)
        {
            if(csum >= 0){
                
                csum += arr[i];    
            }
            
            else{
                csum = arr[i];
            }
            if(csum > osum){
                osum=csum;
            }
        }
        return osum;
    // int x=0;
    // int maxLen= INT_MIN;
    
    // for (int i=0; i<S.length(); i++){  
    //       if (S[i] == '0') x++;
    //       else x--;
           
    //       maxLen = max(maxLen, x);
    //       x = x < 0 ? 0 : x;
    //   }
    //   return maxLen;
	}
};
