class Solution {
  public:
    int countSquares(int N) {
        // code here
        
        int count =0;

        for(int i=1; i*i < N; i++)
        {
        count++;
        }

        return count;
        
    }
};
//second approach
// int x=sqrt(N);

//         if (x*x==N){
//         return x-1;
//         }
//         else return x;
