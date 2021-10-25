
// does not matter if we use queue or deque both will be same in this as there is only push and pop simlpe operations here
vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
                                                 
        long long int i = 0, j = 0;
        vector<long long >ans;
        deque<long long >dq;
        
        while(j < n)
        {
            if(a[j] < 0)
            dq.push_back(a[j]);
            
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                if(!dq.empty())
                ans.push_back(dq.front());
                
                else 
                ans.push_back(0);
                
                if(a[i] < 0)
                dq.pop_front();
                i++;
                j++;
                
            }
        }
             return ans;                                    
                                                 
 }
