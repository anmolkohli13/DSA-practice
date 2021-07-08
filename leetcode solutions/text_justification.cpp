class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n = words.size();
        vector<vector<int>> cost( n , vector<int> (n, INT_MAX));
        
        for(int i = 0; i < words.size(); i++)
        {
            cost[i][i] = maxWidth - words[i].size();
            for(int j=i+1; j < words.size(); j++){
                cost[i][j] = cost[i][j-1] - words[j].size() - 1; 
            }
        }
        
        for(int  i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words.size(); j++)
            {
                if(cost[i][j] < 0)
                {
                    cost[i][j] = INT_MAX;
                    
                }
                else
                {
                    cost[i][j] = pow(cost[i][j],2);
                }
            }
        }
        
        
        int* minCost = new int[words.size()];
        int* result = new int[words.size()];
        
        for(int i = words.size() - 1; i >= 0; i--)
        {
            minCost[i] = cost[i][words.size() - 1];
            result[i] = words.size();
            
            for(int j = words.size() - 1; j > i; j--)
            {
                if(cost[i][j-1] == INT_MAX){
                    continue;
                }
                if(minCost[i] > minCost[j] + cost[i][j-1]){
                    minCost[i] = minCost[j] + cost[i][j-1];
                    result[i] = j;
                }
            }
        }
      
    return minCost[0];
        
    }
};
