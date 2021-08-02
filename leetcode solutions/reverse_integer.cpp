class Solution {
public:
    int reverse(int x) {
        
        // int max = 2e31 - 1;
        // int min = -2e31;
        
        int temp=x,digit=0;
        
        long int ans = 0;
        
        while(temp)
        {
            temp = temp/10;
            digit++;
        }
        
        while(digit--)
        {
            temp = x%10;
            ans = ans + temp*pow(10,digit);
            
            x = x/10;
        }
        
        if(ans < INT_MIN || ans > INT_MAX)
            return 0;
        
        
        
        return ans;
        
        
    }
};
