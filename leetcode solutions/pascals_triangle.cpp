class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<vector<int>> res;
        // for(auto i=0;i < rowIndex+1 ;++i)
        // {
        //     res.push_back(vector<int>(i+1,1));
        //     for(auto j=1; j<i; ++j) res[i][j] = res[i-1][j-1] + res[i-1][j];
        // }
        // return res[rowIndex];
        
        vector<int> ans(rowIndex+1,1);
        
        for(auto i = 1; i < rowIndex; i++){
            for(auto j = i; j >= 1; j--)
                ans[j] += ans[j-1];
        }
        
        return ans;
        
    }
};

