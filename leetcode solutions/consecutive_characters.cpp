class Solution {
public:
    int maxPower(string s) {
        
        int ans=1, power=1;
        
        if(s.size() == 1)
            return 1;
        
        for(int i = 0; i < s.length()-1; i++)
        {
            if(s[i] == s[i+1])
            {
                power++;
                ans = max(ans,power);
            }
            else
                power = 1;
        }
        return ans;
        
    }
};
