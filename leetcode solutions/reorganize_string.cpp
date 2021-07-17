class Solution {
public:
    string reorganizeString(string str) {
     
        priority_queue<pair<int,char>> pq;
        unordered_map<char , int> mp;
        
        for(auto c:str){
            mp[c]++;
            if(mp[c] > (str.length()+1)/2){
                return "";
            }
        }
        
        for(auto x:mp){
            pq.push(make_pair(x.second,x.first));
        }
        
        string res;
        auto temp = pq.top();
        pq.pop();
        res = temp.second;
        temp.first -=1;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            res +=top.second;
            
            if(temp.first>0){
                pq.push({temp.first,temp.second});
            }
            temp = {top.first-1,top.second};
        }
        return res;
        
        
    }
};
