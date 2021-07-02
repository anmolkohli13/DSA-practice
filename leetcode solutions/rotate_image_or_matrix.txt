class Solution {
public:
    
    //simplest and fastest solution
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        
        //transpose of matrix here with traversing in lower triangle only as if you travel in all the ,atrix then the swap           will tak place 2 times and some elements will get back to their original position
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //reverse the rows within themselves to obtain the result
        
        for(int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};