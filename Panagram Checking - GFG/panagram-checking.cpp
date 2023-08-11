//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        vector<char> temp(26,0);
        int t = int('a')-int('A');
        
        int n = str.size();
        for(int i=0;i<n;i++)
        {
            if(int('a')<=int(str[i]) && int(str[i])<=int('z'))
                temp[int(str[i])-int('a')] = 1;
            else if (int('A')<=int(str[i]) && int(str[i])<=int('Z'))
                {
                    int c = int(str[i])+t;
                    temp[c-int('a')] = 1;
                }
        }
        
        for(int i=0;i<26;i++)
        {
            if(temp[i]==0)
                return 0;
        }
        return 1;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends