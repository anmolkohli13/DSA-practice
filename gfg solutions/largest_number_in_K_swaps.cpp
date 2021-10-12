class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string & str, int k, string & max_string,int index){
        if(k == 0){
            return;
        }
        char curr_char = str[index];  
        for(int i = index+1; i < str.length(); ++i) {
            if(str[i] > curr_char) {
                curr_char = str[i]; 
            }
        }
        if(curr_char != str[index]) {
            k--; 
        }    
        for(int i = index; i < str.length(); ++i) {
            if(str[i] == curr_char) {
                swap(str[i], str[index]); 
                max_string = max(max_string, str); 
                solve(str, k, max_string, index+1); 
                swap(str[i], str[index]); 
            }
        }
    }
    
    
    string findMaximumNum(string str, int k)
    {
        int index = 0;  
        string max_string = "";
        solve(str, k, max_string,index); 
        return max_string == "" ? str : max_string; 
    }
};
