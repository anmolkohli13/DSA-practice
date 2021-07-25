// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int n,q,m;
// 	int i,j;
// 	int sol[n],p;

// 	//cout<<"Enter the number of soldiers"<<endl;
//     cin>>n;
// 	//cout<<endl;
// 	//cout<<"Enter the powers of soldiers"<<endl;
// 	for(i = 0; i < n; i++)
// 	{
// 		cin>>sol[i];
// 	}
// 	//cout<<endl;
// 	//cout<<"enter the number of rounds"<<endl;
// 	cin>>q;
// 	//cout<<endl;

//     //cout<<"Enter the power of bishu in each round"<<endl;
// 	// for(i = 0; i < q; i++)
// 	// {
		
// 	// }

// 	for(i = 0; i < q; i++)
// 	{
// 		cin>>p;
// 		int sumstr=0,count=0;
// 		for(j = 0; j < n;j++)
// 		{
// 			if(sol[j] <= p+1)
// 			{
// 				count++;
// 				sumstr += sol[j];
// 			}
// 		}
// 		cout<<count<<" "<<sumstr<<endl;
// 	}


// 	return 0;
// }
#include<bits/stdc++.h>

using namespace std;

#define ll long long


 

int main()

{

    int n;

    cin>>n;

    int ar[n];

    for(int i=0;i<n;i++)

    {

        cin>>ar[i];

    }

    int t;

    cin>>t;

    while(t--)

    {

        int sum=0,count=0;

        int p;

        cin>>p;

        for(int i=0;i<n;i++)

        {

            if(ar[i]<=p){

            sum+=ar[i];

            count++;}

        }

        cout<<count<<" "<<sum<<endl;


 

    }

}
