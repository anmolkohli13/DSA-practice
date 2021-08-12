class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        int* dp = new int[n*n];
        int count = 0;
        
        for(int gap = 0; gap < n; gap++)
        {
            for(int i = 0, j = gap; j < n;i++,j++)
            {
                if(gap == 0)
                {
                    *(dp + i *n + j) = 1;
                }
                else if(gap == 1)
                {
                    if(s[i] == s[j])
                    {
                        *(dp + i *n + j) = 1;
                    }
                    else
                    {
                        *(dp + i *n + j) = 0;
                    }
                }
                else
                {
                    if(s[i] == s[j] && *(dp + (i+1) *n + j-1) == 1)
                    {
                        *(dp + i *n + j) = 1;
                    }
                    else
                    {
                        *(dp + i *n + j) = 0;
                    }
                }
                if(*(dp + i *n + j))
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};