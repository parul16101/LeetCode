//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    
	    int first = INT_MIN, sec = INT_MIN;
	    
	    if(n==1)
	        return -1;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>first)
	        {
	            if(first==INT_MIN && sec==INT_MIN)
	                {
	                    first = arr[i];
	                }
	           else
	           {
	               sec = first;
	               first = arr[i];
	           }
	        }
	        else if (arr[i]<first)
	        {
	            if(arr[i]>sec)
	                sec = arr[i];
	        }
	        else
	            continue;
	    }
	    
	    if(sec==INT_MIN)
	        return -1;
	    return sec;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends