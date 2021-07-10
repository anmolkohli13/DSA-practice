// watched pepcoding video but couldn't make it work so saw the solutioj=n from the discussions and it had the same approach just reverse order but this one worked

class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
     
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(std::find(dict.begin(),dict.end(),word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
        
        
    }
};
