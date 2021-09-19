class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        
        sort(a,a+n);
       long long int i=0;
       while(a[i]<0 and k!=0)
       {
           a[i]=(-1)*a[i];
           i++;
           k--;
       }
       long long int sum=0;
       for(i=0;i<n;i++)
       {
           sum+=a[i];
       }
       if(k==0 or k%2==0)
       return sum;
       
       sort(a,a+n);
       sum=sum-(2*a[0]);
       return sum;
        
        
        
    }
};
