class Solution {
public:
    bool isAnagram(string s, string t) {
     
        int alp[26] = {};
        for(auto x:s)
            alp[x-'a']++;
        for(auto x:t)
            alp[x-'a']--;
        for(auto x:alp)
            if(x!=0)
                return false;
        return true;
    }
};n true;