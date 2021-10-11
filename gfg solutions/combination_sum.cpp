class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void calSum(vector<int> A, int sum, vector<int> &temp, int index, vector<vector<int>> &res)
    {
        if(sum == 0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i = index; i < A.size(); i++)
        {
            if(sum - A[i] >= 0)
            {
                temp.push_back(A[i]);
                sum = sum - A[i];
                
                calSum(A, sum, temp, i, res);
                
                sum = sum + A[i];
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int sum) 
    {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        
        vector<vector<int>> res;
        vector<int> temp;
        
        calSum(A, sum, temp, 0, res);
        
        return res;
    }
};
