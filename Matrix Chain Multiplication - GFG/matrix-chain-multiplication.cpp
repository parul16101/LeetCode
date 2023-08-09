//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[101][101];
    int mcm(int arr[], int i, int j, int N)
    {
        if(i>=j)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
            
        int mini = INT_MAX;
            
        for(int k=i;k<j;k++)
        {
            int temp = arr[i-1]*arr[k]*arr[j] + mcm(arr,i,k,N)+mcm(arr,k+1,j,N);
            
            mini = min(temp,mini);
        }
        
        return t[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
       memset(t,-1,sizeof(t));
       int i=1, j=N-1;
       return mcm(arr,i,j,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends