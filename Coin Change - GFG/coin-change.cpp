//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
            
        long long int t[N+1][sum+1];
        
        for(int i=0;i<=sum;i++)
            t[0][i] = 0;
        for(int i=0;i<=N;i++)
            t[i][0] = 1;
            
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(coins[i-1]<=j)
                    t[i][j] = t[i][j-coins[i-1]]+t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[N][sum];
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends