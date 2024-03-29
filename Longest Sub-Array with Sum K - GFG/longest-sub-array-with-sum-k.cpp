//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> m;
        int presum = 0;
        int ans = INT_MIN;
        for(int i=0;i<N;i++)
        {
            presum += A[i];
            
            if(presum==K)
                ans = max(ans,i+1);
            
            if(m.find(presum-K)!=m.end())
                ans = max(ans, i-m[presum-K]);
            
            if(m.find(presum)==m.end())
                m[presum] = i;
        }
        
        if(ans==INT_MIN)
            return 0;
            
        return ans;
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends