//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool checkPalin(int x)
    {
        string temp = to_string(x);
        int n = temp.size();
        int low = 0, high = n-1;
        while(low<=high)
        {
            if(temp[low]!=temp[high])
                return false;
            low+=1;
            high-=1;
        }
        return true;
    }
  
    int isDigitSumPalindrome(int N) {
        int sum = 0, rem = 0;
        while(N)
        {
            rem = N%10;
            sum += rem;
            N = N/10;
        }
        
        return checkPalin(sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends