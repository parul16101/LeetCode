//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    int l=0, h=n-1;
	    
	    while(l<=h)
	    {
	       int m = (l+h)/2;
	        
	       if(m==l && arr[m]>arr[m+1])
	            return arr[m];
	       else if (m==h && arr[m-1]<arr[m])
	            return arr[m];
	       else if(arr[m-1]<arr[m] && arr[m]>arr[m+1])
	            return arr[m];
	       else if(arr[m-1]<arr[m] && arr[m]<arr[m+1])
	            l = m+1;
	       else if(arr[m-1]>arr[m] && arr[m]>arr[m+1])
	            h = m-1;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends