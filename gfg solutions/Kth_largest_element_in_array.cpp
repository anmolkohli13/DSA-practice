//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    
	    priority_queue<int>pq;
	    
	    for(int i = 0; i < n; i++)
	    pq.push(arr[i]);
	    
	    int temp;
	    vector<int>ans;
	    
	    for(int i = 0; i < k; i++)
	    {
	        temp = pq.top();
	        ans.push_back(temp);
	        pq.pop();
	    }
	    return ans;
	}

};
