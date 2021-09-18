class Solution {
public:
    int maxSubArray(vector<int>& arr) {
     
        int i,csum=arr[0],osum=arr[0],n=arr.size();
        
        for(i=1;i<n;i++)
        {
            if(csum >= 0){
                
                csum += arr[i];    
            }
            
            else{
                csum = arr[i];
            }
            if(csum > osum){
                osum=csum;
            }
        }
        return osum;
        
        
    }
};
