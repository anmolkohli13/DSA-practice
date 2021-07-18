class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        
        if(str1.length() != str2.length())
        return false;
        
        int hash1[256] = {0},hash2[256]={0};
        int i;
        
        for(i = 0; i < str1.length(); i++)
        {
            if(hash1[str1[i]] == 0 && hash2[str2[i]] == 0)
            {
                hash1[str1[i]] = (int)str2[i];
                hash2[str2[i]] = (int)str1[i];
            }
            else
            {
                if(hash1[str1[i]] != (int)str2[i] || hash2[str2[i]] != (int)str1[i])
                return false;
            }
        }
        return true;
    }
};
