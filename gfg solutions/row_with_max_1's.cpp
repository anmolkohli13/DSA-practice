class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	    int ans = -1;
        int i = 0 , j = m-1;
        while((i < n) && (j >= 0)){
        if(arr[i][j] == 1){
        ans = i;
        j--;
        }
        if(arr[i][j] == 0){
        i++;
        }
        }
        return ans;
        
	    // remember that j will point till the max no. of 1's encountered in any row
	}

};
