//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        
        int totalFood = S*M;
        int sun = S/7;
        int buyDay = S-sun;
        
        if(M>N)
            return -1;
        
        if(N==M)
        {
            if(S>6)
                return -1;
        }
        
        int ans = 0;
        
        if(totalFood%N==0)
            ans = totalFood/N;
        else
            ans = (totalFood/N)+1;
            
        if(ans>buyDay)
            return -1;
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends