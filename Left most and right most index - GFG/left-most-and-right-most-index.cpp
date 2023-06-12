//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int leftt(vector<long long> v, long long n, long long x)
    {
        int l = 0, h = n-1;
        int ans = -1;
        while(l<=h)
        {
            int m = (l+h)/2;
            if(v[m]==x)
            {
                ans = m;
                h = m-1;
            }
            else if(v[m]<x)
                l = m+1;
            else 
                h = m-1;
        }
        return ans;
    }
    
    int rightt(vector<long long> v, long long n, long long x)
    {
        int l = 0, h = n-1;
        int ans = -1;
        while(l<=h)
        {
            int m = (l+h)/2;
            if(v[m]==x)
            {
                ans = m;
                l = m+1;
            }
            else if(v[m]<x)
                l = m+1;
            else 
                h = m-1;
        }
        return ans;
    }
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long long n = v.size();
        int left = -1;
        left = leftt(v,n,x);
        int right = -1;
        right = rightt(v,n,x);
        
        pair<long,long> p;
        p.first = left;
        p.second = right;
        return p;
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends