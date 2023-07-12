//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mini(int candies[], int N, int k)
    {
        int i=0, j=N-1;
        int answer = 0;
        
        while(i<=j)
        {
            if(i==j)
            {
                answer += candies[i];
                break;
            }
            else
            {
                answer += candies[i];
                j = j-k;
                i+=1;
            }
        }
        return answer;
        
    }
    
    int maxi(int candies[], int N, int k)
    {
        int i=0, j=N-1;
        int answer = 0;
        reverse(candies, candies+N);
        
        while(i<=j)
        {
            if(i==j)
            {
                answer += candies[i];
                break;
            }
            else
            {
                answer += candies[i];
                j = j-k;
                i+=1;
            }
        }
        return answer;
        
    }
    
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans;
        sort(candies, candies+N);
        int a = mini(candies,N,K);
        int b = maxi(candies,N,K);
        ans.push_back(a);
        ans.push_back(b);
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends