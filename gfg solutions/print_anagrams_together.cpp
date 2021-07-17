vector<vector<string> > Anagrams(vector<string>& strs) 
{
    // Your Code Here
    
    vector<vector<string>>ans;
    
    int n = strs.size();
    if(n==0)
    return ans;
    
    unordered_map<string,vector<string>>mp;
    
    for(auto it : strs)
    {
        string s = it;
        sort(s.begin(),s.end());
        mp[s].push_back(it);  // this is the part which I could not come up with pushing values for a particular group
    }
    
    for(auto i:mp)
        ans.push_back(i.second);  //pushing values of the group into the ans group wise
        
    
    
    return ans;
}
