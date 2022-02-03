/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/

static bool cmp(struct val val1, struct val val2)
{
    return val1.first < val2.first;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,cmp);
    int dp[n];
	    dp[0] = 1;
	    
	    int res = dp[0];
	    
	    for(int i = 1; i < n; i++)
	    {
	        dp[i] = 1;
	        
	        for(int j = 0; j < i; j++)
	        {
	            if(p[j].second < p[i].first)
	            {
	                dp[i] = max(dp[i], 1 + dp[j]);
	            }
	        }
	        
	        res = max(res, dp[i]);
	    }
	    
	    return res;

}
