//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void rev(int arr[], int low, int high, int n)
    {
        while(low<=high)
        {
          swap(arr[low],arr[high]);
          low+=1;
          high-=1;
        }
    }
    
    void leftRotate(int arr[], int n, int d) {
        
        rev(arr,0,d-1,n);
        rev(arr,d,n-1,n);
        rev(arr,0,n-1,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends