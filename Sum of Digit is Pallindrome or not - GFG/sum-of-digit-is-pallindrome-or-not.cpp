//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int palindrome(string s)
    {
        if(s.size()==0 || s.size()==1)
            return 1;
        if(s[0]!=s[s.size()-1])
            return 0;
        return palindrome(s.substr(1,s.size()-2));
    }
    
    int isDigitSumPalindrome(int N) {
        int digit = 0;
        while(N)
        {
            digit += N%10;
            N = N/10;
        }
        
        string s = to_string(digit);
        return palindrome(s);
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