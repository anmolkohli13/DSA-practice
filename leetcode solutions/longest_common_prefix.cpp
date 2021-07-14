class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
//         string ans="";
        
//         for(int i = 1; i < strs.size(); i++)
//         {
//             if(strs[i][0] == strs[0][0])
//             {
//                 for(int j = 0; j < strs.size(); j++)
//                 {
//                     if(strs[i][j] == strs[0][j])
//                         ans += strs[i][j];
//                 }
//             }
//         }
        
//         return ans;
        
        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
};
