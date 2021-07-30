// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // int max,min,i;
        // max=min=arr[0];
        // for(i=1;i<n;i++)
        // {
        //     if(arr[i] < min)
        //     min = arr[i];
        //     else if(arr[i] > max)
        //     max = arr[i];
        // }
        // if((min+k) > 0)
        // min = min+k;
        // if((max-k) > 0)
        // max = max-k;
        // int mindiff=0;
        // mindiff=max-min;
        // return mindiff;
        // sort(arr, arr+n);
        // int minEle, maxEle;
        // int result = arr[n-1] - arr[0];
        
        //below one is better approach than the last one as it is is easier to understand but last one is easier to remeber
        
        // for(int i =1; i<=n-1; i++){
        // if(arr[i]>=k){
        // maxEle = max(arr[i-1] + k, arr[n-1]-k);
        // minEle = min(arr[0]+k, arr[i]-k);
        
        // result = min(result, maxEle-minEle);
        // }
        // else continue;
        // }
        // return result;
        
        sort(arr, arr+n);
        for (int i = 0; i < n; ++i) arr[i]+=k;
        
        int mini = arr[0], maxi=arr[n-1], ans = maxi-mini;
        for (int i = n-1; i >=0 ; --i) {
        arr[i]-= 2*k;
        if (arr[i]<0) break;
        i > 0 ? maxi = max(arr[n-1], arr[i-1]) : maxi = arr[n-1];
        mini = min(arr[0], arr[i]);
        ans = min(ans, maxi-mini);
        }
        return ans;

        }    
        };

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
