class Solution{   
public:
    string smallestNumber(int sum, int d){
        // code here 
        
        string str = "";
        
        if(d*9 < sum)
        return "-1";
        
        vector<int>vec(d,0);
        vec[0] = 1;
        sum = sum-1;
        int j = d-1;
        while(sum > 0)
        {
            if(sum >= 9)
            {
                vec[j] = 9;
                j--;
                sum = sum-9;
            }
            else
            {
                vec[j] = vec[j]+sum;
                sum = 0;
                j--;
            }
        }
        for(int i = 0; i < d; i++)
        {
            str += to_string(vec[i]);
        }
        return str;
        
        
        
    }
};
