//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
       int z=0, t=n-1;
       int i=0;
       
       while(i<=t)
       {
           if(a[i]==0)
           {
               swap(a[i],a[z]);
               i+=1;
               z+=1;
           }
           else if (a[i]==1)
            i+=1;
            else
            {
                swap(a[i],a[t]);
                t-=1;
            }
       }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends