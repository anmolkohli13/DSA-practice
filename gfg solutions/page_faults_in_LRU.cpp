class Solution{
public:

    int pageFaults(int N, int C, int pages[])
    {
        vector<int> v;
        int faults = 0;
        vector<int>::iterator it;
        for(int i = 0; i < N; i++)
        {
            it = find(v.begin(), v.end(), pages[i]);
            if(it == v.end())
            {
                if(v.size() == C)
                v.erase(v.begin());
                v.push_back(pages[i]);
                faults++;
            }
            else
            {
                v.erase(it);
                v.push_back(pages[i]);
            }
        }
        return faults;
    }
};
