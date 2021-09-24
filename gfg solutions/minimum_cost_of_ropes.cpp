class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        long long sum = 0;
       if(n==1) {return sum;}
       priority_queue<long long,vector<long long>, greater<long long>> minh;
       for(long long i=0; i<n; i++) {minh.push(arr[i]);} 
       while(minh.size() >1){
           long long x = minh.top();
           minh.pop();
           long long y = minh.top();
           minh.pop();
           sum += (x+y);
           minh.push(x+y);
       }
       return sum;
    }
};
