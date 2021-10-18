class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        stack<long long> st;
        int i = n-2;
        
        st.push(arr[n-1]);
        ans.push_back(-1);
        
        while(i >= 0)
        {
            while( !st.empty() && st.top() <= arr[i] )
            st.pop();
            
            if(st.empty())
            ans.push_back(-1);
            else
            ans.push_back(st.top());
            
            st.push(arr[i]);
            i--;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
