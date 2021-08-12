int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  
    //this is just the syntax of declaring priority queue and used pair for having the position as well as the element
    priority_queue< pair< int, pair< int, int > >, vector < pair < int, pair < int, int >>>, greater< pair < int, pair < int, int >>>> pq;
    
    for (int i = 0; i < n; i++)
    pq.push({mat[i][0], {i, 0}});
    
    int c = k, ans;
    
    while (c--) {
    int a = pq.top().first;
    int b = pq.top().second.first;
    int c = pq.top().second.second;
    ans = a;
    pq.pop();
    if (c != n - 1)
    pq.push({mat[b][c + 1], {b, c + 1}});
    }
    return ans;
    
    
    
}