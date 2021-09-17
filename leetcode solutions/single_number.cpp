class Solution {
public:
    int singleNumber(vector<int>& a) {
     
        int num = 0;
        // int n = a.size();
     for (int i = 0; i < a.size(); ++i) {
         num ^= a[i];
     }
     return num;
        
        
        
    }
};
