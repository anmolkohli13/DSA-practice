class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int minc=0,minr=0,maxr=r-1,maxc=c-1;
    
    int cnt=0,tne=r*c;
    vector<int>ans;
    int i,j,k=0;
    
    
    while(cnt < tne)
    {
        //top wall
        
        for(i = minr,j = minc; j <=maxc && cnt < tne; j++)
        {
            ans.push_back(matrix[i][j]);
            cnt++;
        }
        minr++;
        
        //right wall
        for(i = minr,j = maxc; i <= maxr &&cnt < tne;i++)
        {
            ans.push_back(matrix[i][j]);
            cnt++;
        }
        maxc--;
        
        //bottom wall
        for(i = maxr,j = maxc;j >= minc &&cnt < tne;j--)
        {
            ans.push_back(matrix[i][j]);
            cnt++;
        }
        maxr--;
        
        //left wall
        for(i = maxr,j = minc; i >= minr &&cnt < tne;i--)
        {
            ans.push_back(matrix[i][j]);
            cnt++;
        }
        minc++;
    }
    
    return ans;
    }
};