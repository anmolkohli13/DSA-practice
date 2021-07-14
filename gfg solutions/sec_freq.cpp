class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        
        map<string , int> mp;
        for(int i = 0; i < n ; i++) mp[arr[i]]++;
        int max1 = INT_MIN , max2 = INT_MIN;
        string s1 = "" , s2 = "";
        for(auto it : mp){
            if(max1 < it.second){
                s2 = s1;
                max2 = max1;
                max1 = it.second;
                s1 = it.first;
            }
            else if(max2 < it.second){
                s2 = it.first;
                max2 = it.second;
            }
        }
        return s2;
        
    }
};
