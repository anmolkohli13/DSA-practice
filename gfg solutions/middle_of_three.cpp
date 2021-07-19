class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        
        int mx = max({A,B,C});
        int mn = min({A,B,C});
        
        return mx^mn^A^B^C;
        
    }
};
