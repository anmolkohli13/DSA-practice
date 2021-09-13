/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
        
    bool myCmp(Job arr1, Job arr2)
    {
    return arr1.profit > arr2.profit;
    }

    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, [](Job arr1, Job arr2){ return arr1.profit > arr2.profit; });
    
    bool done[n] = {0};
    
    int day = 0, profit = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = min(arr[i].dead-1,n); j >= 0; j--)
        {
            if(done[j] == false)
            {
                day += 1;
                profit += arr[i].profit;
                
                done[j] = true;
                
                break;
            }
        }
    }
    return {day, profit};
    }
    
    };
