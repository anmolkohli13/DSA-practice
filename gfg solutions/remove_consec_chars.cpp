class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        
        stack<char>st;
        for(int i = 0; i< S.length(); i++)
        {
            if(st.empty() || st.top() != S[i])
            st.push(S[i]);
        }
        string str ="";
        while(!st.empty())
        {
            char ch = st.top();
            st.pop();
            str += ch;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
