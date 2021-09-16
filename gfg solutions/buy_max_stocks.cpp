#include<bits/stdc++.h>
int maxStock(vector<int> &prices, int n, int amount){
    // Write your code here
    
    vector<pair<int,int>>vec;
    
    for(int i = 0; i < n; i++)
    {
        vec.push_back(make_pair(prices[i],i+1));
    }
    sort(vec.begin(),vec.end());
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        ans += min(vec[i].second,amount/vec[i].first);
        amount -= vec[i].first*min(vec[i].second,amount/vec[i].first);
    }
    return ans;   
}
