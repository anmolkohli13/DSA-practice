class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    // Your code goes here
	    int n = S.size(),flag=0;
	    if(n==1)
	    return 1;
    
    for(int i = 0; i < n/2; i++)
    {
        if(S[i] == S[n-1-i])
        flag = 1;
        
        else
        {
            flag = 0;
            break;
        }
    }
    
    return flag;
	}

};