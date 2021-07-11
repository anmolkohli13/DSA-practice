class Solution{
public:		

		
	int lps(string s)
	{
	    // Your code goes here
	    
	    int  n = s.length();
	    
	    int lps[n];
	    lps[0] = 0;
	    
	    int len  = 0;
	    
	    int  i = 1;
	    
	    while(i < n)
	    {
	        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider
            // the example. AAACAAAA
            // and i = 7. The idea is
            // similar to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do
                // not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
 
    int res = lps[n-1];
 
    // Since we are looking for
    // non overlapping parts.
    return res;
    
	    
	}
};
