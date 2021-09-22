#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	
	while(true)
	{
		long long  n;
		cin>>n;
		if(n==0)
		break;
		long long int arr[n];
		vector<long long int>pre;
		for(long long int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		long long int sum = 0;
		for(long long int i = 0; i< n; i++)
		{
			sum +=arr[i];
			pre.push_back(sum);
		}
		long long int ans = 0;
		for(long long int i = 0; i < n; i++)
		{
			ans += abs(arr[i]-pre[i]);
		}
		
		cout<<ans<<endl;
		// int temp;
		// cin>>temp;
		// if(temp==0)
		// break;
		
	}
	
	
	return 0;
}
