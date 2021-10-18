class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        
        stack<int> st;
        
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] >= '0' && S[i] <= '9')
            {
                int temp = S[i]-'0';
                st.push(temp);
            }
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c;
                switch(S[i])
                {
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = b - a;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = b / a;
                        break;
                }
                st.push(c);
            }
        }
        return st.top();
        
    }
};
