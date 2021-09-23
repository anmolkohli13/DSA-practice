#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	// cout<<endl;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		int x[m],y[n];
		for(int i = 1; i < m; i++)
		{
			cin>>x[i];
		}
		for(int i = 1; i < n; i++)
		{
			cin>>y[i];
		}
		int ans = 0;
		int h = 1, v = 1;
		sort(x+1,x+m,greater<int>());
		sort(y+1,y+n,greater<int>());
		
		int i = 1, j = 1;
		
		while(i < m && j < n)
		{
			if(x[i] > y[j])
			{
				ans += x[i]*v;
				i++;
				h++;
			}
			else{
				ans += y[j]*h;
				j++;
				v++;
			}
		}
		if(i<m){
            int sum = 0;
            while(i<m){
                sum += x[i];
                ++i;
            }
            ans += sum*v;
        } else {
            int sum = 0;
            while(j<n){
                sum += y[j];
                ++j;
            }
            ans += sum*h;
        }
        cout << ans << endl;
		
		
		
		
	}
	
	
	
	return 0;
}
