//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int p = 0;
        int ans = 0;
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
            {
                if(arr[i]==0)
                    arr[i] = -1;
            }
        
        for(int i=0;i<n;i++)
        {
            p += arr[i];
            
            if(m.find(p)!=m.end())
            {
                 ans+=m[p];
            }
            
            m[p]+=1;
            
            if(p==0)
                ans+=1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends