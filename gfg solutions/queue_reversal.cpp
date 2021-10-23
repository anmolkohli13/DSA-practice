//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    
    stack<int>st;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        st.push(temp);
    }
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    return q;
