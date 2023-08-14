//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]] += 1;
        }
        
        string name = "";
        int freq = INT_MIN;
        
        for(auto i:m)
        {
            if(i.second>freq)
            {
                freq = i.second;
                name = i.first;
            }
            else if(i.second==freq)
            {
                if(i.first<name)
                    name = i.first;
            }
        }
        
        vector<string> ans;
        ans.push_back(name);
        ans.push_back(to_string(freq));
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends