class Solution{
  public:
  
    bool flag; 
    void solve(int arr[],int i,int n,int k,int subsetsum[],int ssf)
    {
      if(i==n){
       if(ssf==k){ 
           int b=1;
        for(int j=0;j<k-1;j++){
        
        if(subsetsum[j]!=subsetsum[j+1]){
            b=0;
            break;
        }}
        if(b) flag=true;
       }  
       return;
      }
      for(int j=0;j<k;j++){
        if(subsetsum[j]>0){
            subsetsum[j]+=arr[i];
            solve(arr,i+1,n,k,subsetsum,ssf);
            subsetsum[j]-=arr[i];
        }
        else{
            subsetsum[j]+=arr[i];
            solve(arr,i+1,n,k,subsetsum,ssf+1);
            subsetsum[j]-=arr[i];
            break;
        }
      }
    }
    bool isKPartitionPossible(int arr[], int n, int k)
    { 
      if(n<k||n==0||k==0) return false;
      if(k==1) return true;
     flag=false; 
     int subsetsum[k]={0};  
     int sum=0;
     for(int i=0;i<n;i++) 
     sum+=arr[i];
     if(sum%k>0) return false;
     else 
     solve(arr,0,n,k,subsetsum,0);
     return flag;
    }
};
