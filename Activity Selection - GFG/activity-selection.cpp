//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> meeting;
        for(int i=0;i<n;i++)
        {
            meeting.push_back({end[i],start[i]});
        }
        
        sort(meeting.begin(), meeting.end());
        
        int count = 1;
        
        int endd = meeting[0].first;
        
        for(int i=1;i<n;i++)
        {
            if(endd<meeting[i].second)
            {
                count+=1;
                endd = meeting[i].first;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends