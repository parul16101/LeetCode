//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long s = 0;
        long long ans = INT_MIN;
        
        int neg = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<0)
                neg+=1;
        }
        
        if(neg==n)
        {
            int a = arr[0];
            for(int i=1;i<n;i++)
                {
                    if(arr[i]>a)
                        a = arr[i];
                }
                return a;
        }
        
        for(int i=0;i<n;i++)
        {
            s += arr[i];
            
            if(s<0)
                s=0;
            else
                ans = max(ans,s);
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends