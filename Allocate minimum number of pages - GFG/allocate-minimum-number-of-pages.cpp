//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int isValid(int A[], int pages, int N)
    {
        int cnt = 1, sum = 0;
        
        for(int i=0;i<N;i++)
        {
            if(sum+A[i]<=pages)
            {
                sum = sum+A[i];
            }
            else
            {
                cnt+=1;
                sum = A[i];
            }
        }
        return cnt;
        
    }
    
    int findPages(int A[], int N, int M) 
    {
        //edge cases 
        //a - when N<M - ret -1
        //b - when not possible - ret -1
        int res = -1;
        
        if(N<M) return -1;
        
        int sum = 0, maxi = INT_MIN;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            maxi = max(maxi,A[i]);
        }
        
        int low = maxi, high = sum;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(isValid(A,mid,N)<=M)
            {
                res = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends