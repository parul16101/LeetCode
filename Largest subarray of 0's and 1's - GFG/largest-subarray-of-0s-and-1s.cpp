//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        int n = N;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                arr[i] = -1;
        }
        
        int pre_sum = 0, len = 0, ans = INT_MIN;
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            pre_sum += arr[i];
            
            if(pre_sum==0)
            {
                len = i+1;
                ans = max(ans,len);
            }
            
            if(m.find(pre_sum)==m.end())
                m[pre_sum] = i;
            else
            {
                len = i-m[pre_sum];
                ans = max(ans,len);
            }
        }
        
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends