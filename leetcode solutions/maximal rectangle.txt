class Solution {
public:
    
    int LAH(vector<int>& heights) {
     
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        //vector<vector<int>> &M = std::stoi(std::char(matrix.begin(),matrix.end()));
        
        
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            
            result = max(result, LAH(histogram));
            cout<<result<<" ";
        }
        return result;
    }
        
        

};