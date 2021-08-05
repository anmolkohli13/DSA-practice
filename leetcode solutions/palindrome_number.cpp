class Solution {
public:
    
    int reverse(int x)
    {
        long int digit = 0,rev=0,temp=x;
        while(temp)
        {
            digit++;
            temp/=10;
        }
        while(digit--)
        {
            
            rev = rev + (x%10)*pow(10,digit);
            x/=10;
        }
        return rev;
    }
    
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;
        
        long int rev = reverse(x);
        if(rev < INT_MIN || rev > INT_MAX)
            return false;
        
        return rev==x;      
    }
};
