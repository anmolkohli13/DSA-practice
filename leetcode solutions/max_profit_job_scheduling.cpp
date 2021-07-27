// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//     map<int, int> times;
//     unordered_map<int, vector<pair<int, int>>> jobs;
//     for (auto i = 0; i < startTime.size(); ++i) {
//         times[startTime[i]] = 0;
//         jobs[startTime[i]].push_back({ endTime[i], profit[i] });
//     }    
//     int max_profit = 0;
//     for (auto it = rbegin(times); it != rend(times); ++it) {
//         for (auto job : jobs[it->first]) {
//             auto it = times.lower_bound(job.first);
//             max_profit = max(max_profit, (it == end(times) ? 0 : it->second) + job.second);
//         }
//         it->second = max_profit;
//     }
//     return max_profit;
// }  
// };
class Solution {
public:
    
    int go(int index, vector<int>& A, vector<int>& B, vector<int>& C, vector<int> &dp){
        int n = A.size();
		// if index is the last possible valid index then return the profit for selecting this job
        if(index == n-1) return C[index];
		// check if max profit for this index has been previously calculated, if yes return it
        if(dp[index] != -1)return dp[index];
		// find the next possible job that can be undertaken after this job
        auto y = lower_bound(A.begin()+index, A.end(), B[index]);
        int x, z; // x for undertaking the job, z for not undertaking the job
        if(y == A.end()){
			// if no job can be undertaken after this, x = the profit gained from this job
             x = C[index];
        }else{
			// else x = profit gained from this job + max profit from the job which can be taken next
            x = C[index] + go(y-A.begin(), A, B, C, dp);
        }
		// z = max profit by skipping this job and taking the next available job
        z = go(index +1, A, B, C, dp);
		// answer would be the max(x,z) to maximize profit and would be stored in dp[index]
        dp[index] = max(x, z);
        return max(x, z);
    }
    
    static bool comp(vector<int> &A, vector<int> &B){
        if(A[0] == B[0]){
            if(A[1] == B[1]){
                return A[2] > B[2];
            }
            return A[1] < B[1];
        }
        return A[0] < B[0];
    }
    
    int jobScheduling(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
		// sort the jobs according to their start times
        vector<vector<int>> AA;
        for(auto i = 0; i<n; i++){
            AA.push_back({A[i], B[i], C[i]});
        }
        sort(AA.begin(), AA.end(), comp);
        A.clear();
        B.clear();
        C.clear();
		// fill A, B, C back again 
        for(auto &a: AA){
            A.push_back(a[0]);
            B.push_back(a[1]);
            C.push_back(a[2]);
        }
		// initialise dp vector
        vector<int> dp(n, -1);
        return go(0, A, B, C, dp);
    }
};
