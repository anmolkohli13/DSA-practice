class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // code here   
	    
	   // vector<vector<int>>ans(n,vector<int>(n,0));
	   // int row = 0, col = 0;
	    
	   // for(int j = n-1 ; j >= 0; j--)
	   // {
	   //     for(int i = 0; i < n; i++)
	   //     {
	   //         ans[row][col] = arr[i][j];
	   //         col++;
	   //     }
	   //     row++;
	   //     col = 0;
	   // }
	    
	   // for(int i = 0; i < n; i++)
	   // {
	   //     for(int j = 0; j < n; j++)
	   //     {
	   //         cout<<ans[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	   
	   for(int i = 0; i < n ; i++)
	   {
	       reverse(arr[i].begin(),arr[i].end());
	   }
	   
	   for(int i = 0; i < n; i++)
	   {
	       for(int j = 0; j < i; j++)
	       {
	           swap(arr[i][j],arr[j][i]);
	       }
	   }
	   
	   
	    
	}

};
