//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<bool> arr(N+1,true);
        
        for(int i=2;i*i<=N;i++)
        {
            if(arr[i]==true)
            {
                for(int j=i*i;j<=N;j+=i)
                {
                    arr[j] = false;
                }
            }
        }
        
        vector<int> ans;
        for(int i=2;i<=N;i++)
        {
            if(arr[i]==true)
                ans.push_back(i);
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
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends