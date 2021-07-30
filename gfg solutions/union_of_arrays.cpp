class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        
       unordered_set<int> st;
        
        st.insert(a, a + n);
        st.insert(b, b + m);
        
        return st.size();
                
    }
};
