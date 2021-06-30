//solution using the approach of next greater element applied on the left and right boundaries
//watched the pepcoding video for the question 
//NOTE-notice that here the element is not passed but the index of the elements is passed

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     
        int n = heights.size();
        
        vector<int>rb(n,n);
        stack<int>st;
        
        st.push(n-1);
        rb[n-1]=n;
        
        for(int i = n-2; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                rb[i] = n;
            }
            else
            {
                rb[i] = st.top();
            }
            st.push(i);
        }
        
        vector<int>lb(n,-1);
        stack<int>st1;
        
        st1.push(0);
        lb[0] = -1;
        
        for(int i = 1; i < n; i++)
        {
            while(!st1.empty() && heights[st1.top()] >= heights[i])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                lb[i] = -1;
            }
            else
                lb[i] = st1.top();
            
            st1.push(i);
        }
        
        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            int width = rb[i]-lb[i]-1;
            int area = heights[i]*width;
            
            if(area > maxArea)
                maxArea = area;
        }
        
        //return area;
        return maxArea;
    }
};