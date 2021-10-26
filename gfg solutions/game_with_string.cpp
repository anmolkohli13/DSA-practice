class Solution{
public:
    int minValue(string s, int k){
        // code here
       unordered_map<char,int>mp;
       sort(s.begin(),s.end());
       
       for(int i = 0; i < s.length(); i++)
       {
           mp[s[i]]++;
       }
       priority_queue<int>pq;
       for(int i = 0; i < mp.size(); i++)
       {
            pq.push(mp[i]);
       }
       
       for(int i = 0; i < k; i++)
       {
           int temp = pq.top();
           pq.pop();
           temp--;
           pq.push(temp);
       }
       int sum = 0;
       for(int i = 0; i < pq.size(); i++)
       {
           int temp = pq.top();
           sum += pow(temp,2);
           pq.pop();
       }
       return sum;
       
    }
};
