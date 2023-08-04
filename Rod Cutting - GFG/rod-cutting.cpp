//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> wt(n,0);
        for(int i=1;i<=n;i++)
            wt[i-1] = i;
        
        int N = n;
        //N-W-cap
        //wt 
        int t[N+1][N+1];
        
        for(int i=0;i<=N;i++)
            {t[0][i] = 0;
            t[i][0] = 0;}
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(wt[i-1]<=j)
                    t[i][j] = max(price[i-1]+t[i][j-wt[i-1]], t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[N][N];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends