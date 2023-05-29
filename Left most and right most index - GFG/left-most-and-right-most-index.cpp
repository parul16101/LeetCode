//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    long bsleft(vector<long long> v, long long x)
    {
        long n = v.size();
        long l = 0, h = n-1;
        
        while(l<=h)
        {
            long m = (l+h)/2;
            
            long temp = v[m];
            
            if(temp==x)
            {
                if(m==0)
                    return m;
                else if(v[m-1]!=v[m])
                    return m;
                else
                    h = m-1;
            }
            else if(temp<x)
                l = m+1;    
            else
                 h = m-1;
        }
        return -1;
    }
    
    long bsright(vector<long long> v, long long x)
    {
        long n = v.size();
        long l = 0, h = n-1;
        
        while(l<=h)
        {
            long m = (l+h)/2;
            
            long temp = v[m];
            
            if(temp==x)
            {
                if(m==n-1)
                    return m;
                else if(v[m+1]!=v[m])
                    return m;
                else
                    l = m+1;
            }
            else if(temp<x)
                l = m+1;    
            else
                 h = m-1;
        }
        return -1;
    }
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long left = 0, right = 0;
        pair<long,long> ans;
        
        left = bsleft(v,x);
        right = bsright(v,x);
        ans.first = left;
        ans.second = right;
        return ans;
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