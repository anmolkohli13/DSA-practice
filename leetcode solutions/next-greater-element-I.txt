// first solution is seen from discussion it uses slightly different approach

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        unordered_map<int,int>m;
        
        for(int n:nums2)
        {
            while(s.size() && s.top() < n)
            {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int>ans;
        
        for(int n:nums1)
            ans.push_back(m.count(n)?m[n]:-1);
        
        
        return ans;
        
        
    }
};

//this one uses the same approach as pepcoding just different way of the question so had to use maps\

map<int,int>m1; 
    stack<int>st;
     int n=nums2.size();
    
  for(int i=n-1;i>=0;i--){
      
      while(!st.empty() && st.top()<nums2[i]){
          st.pop();
      }

      if(st.empty()){
          m1[nums2[i]]=-1;
      }
      
      else{
          m1[nums2[i]]=st.top();
      }
      
      st.push(nums2[i]);

      
  }
    vector<int>ans;
    
    for(auto i:nums1){
        ans.push_back(m1[i]);
    }
    
    
    return ans;
