//this solution is done like the explanantion on gfg but on leetcode it gives stack overflow error
//there is a better solution for this by binary search

class Solution {
public:
    
    double MO2(int a,int b){
        return (a+b)/2.0;        
    }
    
    double MO3(int a,int b,int c)
    {
        return a+b+c - max(a,max(b,c)) - min(a,min(b,c));
    }
    
    double MO4(int a,int b,int c,int d)
    {
        int Max = max(a,max(b,max(c,d)));
        int Min = min(a,min(b,min(c,d)));
        
        return (a+b+c+d-Max-Min)/2.0;
    }
    double MedianSingle(vector<int>arr,int n)
    {
        if(n==0)
            return -1;
        if(n%2==0)
            return (arr[n/2]+arr[n/2-1])/2.0;
        return arr[n/2];            
    }
    
    double findMedian(vector<int>A,int n,vector<int>B,int m)
    {
        if(n==0)
            return MedianSingle(B,m);
        if(n==1)
        {
            if(m==1)
            {
                return MO2(A[0],B[0]);
            }
            
            if(m & 1)
            return MO2(B[m/2],MO3(A[0],B[m/2-1],B[m/2+1]));
            
        }
        
        else if(n==2)
        {
            if(m==2)
                return MO4(A[0],B[0],A[1],B[1]);
            if(m & 1)
            return MO3(B[m/2],max(A[0],B[m/2-1]),min(A[1],B[m/2+1]));
            
            return MO4(B[m/2],B[m/2-1],max(A[0],B[m/2-2]),min(A[1],B[m/2+1]));
            
        }
        
        int idxA = ( n - 1 ) / 2;
        int idxB = ( m - 1 ) / 2;
        
        vector<int>A1 = vector<int>(A.begin()+idxA,A.end()); 
        vector<int>B1 = vector<int>(B.begin()+idxB,B.end());
        
        if (A[idxA] <= B[idxB] )
        return findMedian(A1, n/2 + 1, B, m - idxA );
        
        return findMedian(A, n/2 + 1, B1, m - idxA );
        
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     
        int n,m;
        
        n = nums1.size();
        m = nums2.size();
        
        if(n>m)
            return findMedian(nums2,m,nums1,n);
        
        return findMedian(nums1,n,nums2,m);
        
    }
};