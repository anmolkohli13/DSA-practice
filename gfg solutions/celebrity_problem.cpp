class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // int start = 0;
        // int end = n - 1;
        // while (start < end)
        // {
        // if (M[start][end] == 1)
        // start++;
        // else
        // end--;
        // }
        // for (int i = 0; i < n; i++)
        // {
        // if ( (i != start) && (M[start][i] == 1 || M[i][start] == 0))
        // return -1;
        // }
        
        
        // return start;
        stack<int>s;
        for (int i = 0; i < n; i++) {
        s.push(i);
        }
        while (s.size() >= 2) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if (M[a][b] == 0)
        s.push(a);
    
        else
        s.push(b);
        
        }
        
        int ans = s.top();
        for (int i = 0; i < n; i++) {
            if (i != ans) {
                if (M[i][ans] == 0 || M[ans][i] == 1)
                return -1;
            }
        }
        return ans;
    }
};
