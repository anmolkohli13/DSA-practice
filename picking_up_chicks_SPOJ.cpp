#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	for(int x = 1; x <= t; x++)
	{
		int n,k,b,t;
		cin>>n>>k>>b>>t;
		int pos[n];
		for(int i = 0; i < n; i++)
		{
			cin>>pos[i];
		}
		int vel[n];
		for(int i = 0; i < n; i++)
		{
			cin>>vel[i];
		}
		
		long num = 0;
        long result = 0;
        long swap = 0;

        for(int j = n - 1; j >= 0; j--)
        {
            long long distanceCover = vel[j] * t;
            long long distanceToCover = b - pos[j];

            if(distanceToCover <= distanceCover)
            {
                num++;

                if(swap > 0)
                {
                    result += swap;
                }
            }
            else
            {
                swap++;
            }

            if(num == k)
                break;
        }

        if(num < k)
        {
            cout << "Case #" << x << ": IMPOSSIBLE\n";
        }
        else
        {
             cout << "Case #" << x << ": " << result << endl;
        }

			
	}
	
	
	
	return 0;
}
