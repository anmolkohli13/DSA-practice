class Solution{
public:

    unordered_map<string,int>mp;

    int solve(string &str,int i, int j, int expr)
    {
        if(i > j)
        return 0;
        
        if(i == j )
        {
            
            if( (str[i] == 'T' && expr == 1) || (str[i] == 'F' && expr == 0) )
            return 1;
            
            else
            return 0;
        }
        string temp = to_string(i) + " " + to_string(j) + " " + to_string(expr);
        
        if(mp.find(temp) != mp.end())
            return mp[temp];
            
        int ans = 0;
        
        for(int k = i + 1; k <= j-1; k += 2)
        {
            int lt = solve(str,i,k-1,1);
            int lf = solve(str,i,k-1,0);
            int rt = solve(str,k+1,j,1);
            int rf = solve(str,k+1,j,0);
            
            if(str[k] == '&')
            {
                if(expr == 1)
                ans += (lt*rt);
                else
                ans += ((lt*rf)+(lf*rf)+(lf*rt));
            }
            else if(str[k] == '|')
            {
                if(expr == 1)
                ans += ((lt*rt)+(lt*rf)+(lf*rt));
                else
                ans += (lf*rf);
            }
            else if(str[k]=='^')
            {
                if(expr == 1)
                ans += ((lt*rf)+(lf*rt));
                else
                ans += ((lt*rt)+(lf*rf));
            }
            
        }
        return mp[temp] = ans%1003;
        
    }


    int countWays(int n, string str){
        mp.clear();
        return solve(str,0,n-1,1);
        
    }
};
