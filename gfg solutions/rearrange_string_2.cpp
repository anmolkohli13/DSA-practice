#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string rearrangeString(string str)
    {
        //code here
        
        //this uses the same approach as kevin naughton video just this is for c++
        // see this as this a good question and also has implementation of maxheap using priority queue
        
        priority_queue<pair<int,char>> pq;
        unordered_map<char , int> mp;
        
        for(auto c:str){
            mp[c]++;
            if(mp[c] > (str.length()+1)/2){
                return "-1";
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


int main() {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    string ans = rearrangeString(str);
	    if(ans != "-1")
	    {
	        cout<<"1"<<endl;
	    }
	    else
	    cout<<"0"<<endl;
	   // cout<<ans<<endl;
	    
	}
	
	
	return 0;
}
