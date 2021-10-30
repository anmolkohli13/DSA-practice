typedef pair<int,int> pi;

class Solution
{
   public:
   //Function to merge k sorted arrays.
   vector<int> mergeKArrays(vector<vector<int>> arr, int k)
   {
       priority_queue<pi,vector<pi>,greater<pi>> pq;
       vector<int> idx(k,0);
       
       for(int i=0;i<k;i++)
       pq.push(make_pair(arr[i][0],i));
       
       int n = arr[0].size();
       vector<int> ans;
       
       while(!pq.empty()){
           pi t = pq.top();
           ans.push_back(t.first);
           idx[t.second]++;
           pq.pop();
           
           if(idx[t.second]<k)
           pq.push(make_pair(arr[t.second][idx[t.second]],t.second));
       }
       return ans;
       //code here
   }
};
