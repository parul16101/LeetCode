//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int repeat = 0,  missing = 0;
        for(int i=0;i<n-1;i++)
        {
            if(repeat!=0 && missing!=0)
                break;
            if((arr[i+1]-arr[i])==0)
                repeat = arr[i];
            else if(arr[i+1]-arr[i]==2)
                missing = (arr[i+1]+arr[i])/2;
                
        }
        if(missing==0)
        {
            if(arr[0]!=1)
                missing = 1;
            else 
                missing = n;
        }
        
        
        ans.push_back(repeat);
        ans.push_back(missing);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends