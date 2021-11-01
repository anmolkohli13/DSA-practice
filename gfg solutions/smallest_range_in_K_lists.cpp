#define p pair<int,pair<int,int>>
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue<p,vector<p>,greater<p>>q;
          int min = INT_MAX;
          int max = INT_MIN;
          int low = 0, high = 0, range = INT_MAX;
          
          for(int i = 0; i < k; i++)
          {
              int temp = arr[i][0];
              if(temp > max)
              max = temp;
              if(temp < min)
              min = temp;
              q.push({arr[i][0],{i,0}});
          }
          
          while(true)
          {
              p temp = q.top();
              q.pop();
              
              int min1 = temp.first;
              
              if(range > max-min1){
                  min = min1;
                  low = min;
                  high = max;
                  range = max-min;
              }
              
              int i = temp.second.first;
              int j = temp.second.second;
              
              if(j == n-1)
              break;
              
              q.push({arr[i][j+1],{i,j+1}});
              if(max < arr[i][j+1])
              {
                  max = arr[i][j+1];
              }
              
          }
          return {low,high};
          
    }
};
