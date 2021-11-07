class Solution {
public:
    //Use an unordered_map to group the strings by their sorted counterparts. Use the sorted string as the key and all anagram strings as the value.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;

    }
};
