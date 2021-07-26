//#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool compute(int ht[],int n,int m,int mid)
{
    int sum = 0;
    for(int i = n-1; i >= 0; i--)
    {

        sum = sum + ht[i]-mid;
        if(sum >= m)
        {
            return true;
        }

    }
    return false;
}

int main()
{
    int n,m,i=0;
    //cout<<"enter number of trees and wood required in meters"<<endl;
    cin>>n>>m;
    int ht[n];
    //cout<<"Enter the heights of the trees"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ht[i];
    }
    sort(ht,ht+n);

    int low = ht[0],high = ht[n-1];
    int ans = high;
    while(low <= high)
    {
        int mid = (low+high)>>1;

        if(compute(ht,n,m,mid))
        {
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }

    //int ans = compute(ht,n,m);
    cout<<ans;
    return 0;
}
