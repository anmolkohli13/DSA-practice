#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int h,a;
		cin>>h>>a;
		int days=1;
		int c=0;
		int i=0;
		while(h>0 && a>0)
		{
			if(i%2==0)
			{
				h+=3;
				a+=2;
				c++;
				
			}
			else 
			{
				if((h-5)>0 && (a-10)>0)
				{
					c++;
					h-=5;
					a-=10;
				}
				else if((h-20)>0 && (a+5)>0)
				{
					c++;
					h-=20;
					a+=5;
				}
				else
				{
					break;
				}
			}
			i++;
		}
		cout<<c<<"\n";
		
		
	}
	
	
	return 0;
}
