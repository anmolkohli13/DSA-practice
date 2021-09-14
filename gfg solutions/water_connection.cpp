class Solution
{
    public:
    // I actually solved this question ,But I didn't understood why its a greedy problem. 
// Because I didn't used any greedy approach in any function except while assigning the diameter to 
// different houses in wt[]. In editorial there is no use of greedy approach not even while 
// assigning wt[].


// the function that does the dfs
int solv(int gp[],int cp[],int wt[],int i,int &min_dia){
    if(gp[i] == 0)
        return i;
    min_dia = min(min_dia,min(wt[gp[i]],wt[i]));
    return solv(gp,cp,wt,gp[i],min_dia);
}
// here the solution starts,the funcion that is asked to be completed
vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
{
    int cp[n+1] = {0}; // this array is for incoming pipe house for example cp[2] = 3 so pipe is coming 3 to 2
    int gp[n+1] = {0}; //this array is for outgoing pipe house for example gp[2] = 3 then pipe is going from 2 to 3
    int wt[n+1]; //this array is for minimum diameter of pipe in each house
    memset(wt,10000,sizeof(wt));
    vector<vector<int>> ans;
    // The mapping of houses to each other 
    // here greedy approach is used to find and assign  the minimum diameter of pipe associated with each house
    
    for(int i=0;i<p;i++){
        gp[a[i]] = b[i];
        cp[b[i]] = a[i];
        wt[a[i]] = min(wt[a[i]],d[i]); 
        wt[b[i]] = min(wt[b[i]],d[i]); 
    }
    // In this for loop dfs is done on every house where there is only outgoing pipe and no 
    // incoming pipe
    
    for(int i=1;i<=n;i++){
        if(gp[i]!=0 and cp[i] == 0){
            vector<int> vec;
            int min_dia=INT_MAX;
            vec.push_back(i);  // the house in which only one outgoing pipe and no incoming pipe 
                               // which would also be the start of network is added 
            vec.push_back(solv(gp,cp,wt,i,min_dia));  // dfs function returns the house with only one 
                                                      // incoming pipe and no outgoing pipe which would 
                                                      // also be the end of network. 
            vec.push_back(min_dia);   // the min dia of all the pipes in the network is also calculated 
                                      // while doing DFS
            ans.push_back(vec);
        }
    }
    
    return ans;
}
};
