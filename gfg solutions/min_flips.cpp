int minFlips (string s)
{
    // your code here
    
    int n = s.size();
    int f1 = 0;
    int f2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        // this condition is for checking the 010101 pattern for the entire length of the string
        if(i%2 == s[i] - '0')
        {
            f1++;
        }
        // this is for checking 10101010 pattern
        else
        f2++;
    }
    return min(f1,f2);
    
}
