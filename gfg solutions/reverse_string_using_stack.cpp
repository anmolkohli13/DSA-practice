char* reverse(char *S, int len)
{
    //code here
    
    stack<char>st;
    int i;
    for(i = 0; i < len; i++)
    {
        st.push(S[i]);
    }
    char *rev = new char[len+1];
    i = 0;
    while(!st.empty())
    {
        rev[i] = st.top();
        st.pop();
        i++;
    }
    rev[len]='\0';
    return rev;
    
}
