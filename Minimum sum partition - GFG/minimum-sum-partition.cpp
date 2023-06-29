//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	    int sum = 0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	    
	    vector<bool> temp(sum+1,false);
	    
	    bool t[n+1][sum+1];
	    for(int i=0;i<=sum;i++)
	        t[0][i] = false;
	    for(int i=0;i<=n;i++)
	        t[i][0] = true;
	        
	   for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=sum;j++)
	       {
	           if(arr[i-1]<=j)
	               t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
	           else
	               t[i][j] = t[i-1][j];
	       }
	   }
	   
	   for(int i=0;i<=sum;i++)
	   {
	        temp[i] = t[n][i];
	   }
	   
	   int ans = INT_MAX;
	   int d = 0;
	   
	   for(int i=0;i<=sum;i++)
	   {
	       if(temp[i])
	        {
	            d = abs(2*i-sum);
	            ans = min(ans,d);
	        }
	   }
	   return ans;
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends