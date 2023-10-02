//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        
        for(int i=0;i<=n-3;i++)
        {
            int first = A[i];
            
            int j = i+1;
            int k = n-1;
            
            while(j<k)
            {
                int second = A[j]+A[k];
                
                int sum = first+second;
                
                if(sum==X)
                    return true;
                else if(sum<X)
                    j+=1;
                else
                    k-=1;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends