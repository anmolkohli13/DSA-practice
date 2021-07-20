class Solution{
public:

// go at this link for the explanation of finding frequence of limited range array elements
//  https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1#

    int *findTwoElement(int *arr, int N) {
        // code here
        
        int *res = new int(2);
        
        for(int i = 0; i < N; i++)
        {
            arr[i] -= 1;
        }
        
        for(int i = 0; i < N; i++)
        {
            arr[arr[i] % N] += N;
        }
        
        for(int i = 0; i < N; i++)
        {
            arr[i] /= N;
            
            if(arr[i] == 2)
            {
                res[0] = i + 1;
            }
            
            if(arr[i] == 0)
            {
                res[1] = i + 1;
            }
        }
        
        return res;
        
        
        
    }
};
