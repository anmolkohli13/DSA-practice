class Solution {
public:
    int candy(vector<int>& ratings) {
     

        int size=ratings.size();
	 if(size<=1)
		 return size;
	 vector<int> num(size,1);
	 for (int i = 1; i < size; i++)
	 {
		 if(ratings[i]>ratings[i-1])
			 num[i]=num[i-1]+1;
	 }
	 for (int i= size-1; i>0 ; i--)
	 {
		 if(ratings[i-1]>ratings[i])
			 num[i-1]=max(num[i]+1,num[i-1]);
	 }
	 int result=0;
	 for (int i = 0; i < size; i++)
	 {
		 result+=num[i];
		// cout<<num[i]<<" ";
	 }
	 return result;
        
        //         int n  = ratings.size();
//         int ans = n;
        
//         for(int i = 0; i < n; i++)
//         {
//         if( i > 0 && i < n-1 && (ratings[i] > ratings[i-1] || ratings[i] > ratings[i+1]))
//                 ans++;
//          else if( i == 0 && (ratings[i] > ratings[i+1]))
//              ans++;
//          else if(i == n-1 && (ratings[i-1] < ratings[i]))
//              ans++;
            
//         }
        
//         return ans;
        
        
    }
};

