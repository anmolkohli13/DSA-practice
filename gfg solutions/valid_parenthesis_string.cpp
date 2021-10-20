class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        // stack<int>st;
        // st.push(-1);
        // int ans = 0;
        // for (int i = 0; i < s.size(); i++) {
            
        //     if (s[i] == '(')
        //             st.push(i);
        //     else {
        //         if (!st.empty())
        //             st.pop();
                
        //         if (!st.empty())
        //             ans = max(ans, i - st.top());
        //         else
        //             st.push(i);
        // }
        
        // }
        
        // return ans;
        
        int res = 0;
        
        int open = 0;
        int close = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open == close)
            {
                res = max(res, 2 * open);
            }
            else if(close > open)
            {
                open = close = 0;
            }
        }
        
        open = close = 0;
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open == close)
            {
                res = max(res, 2 * open);
            }
            else if(open > close)
            {
                open = close = 0;
            }
        }
        
        return res;
    }
};
