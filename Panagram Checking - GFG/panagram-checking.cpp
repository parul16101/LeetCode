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
        
        int t = int('a')-int('A');
        
        vector<bool> arr(26,false);
        
        for(int i=0;i<str.size();i++)
        {
            if(int('a')<=int(str[i]) && int(str[i])<=int('z'))
                arr[int(str[i])-int('a')] = true;
            else if(int('A')<=int(str[i]) && int(str[i])<=int('Z'))
                {
                    arr[(int(str[i])+t)-int('a')] = true;
                }
        }
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]==false)
                return false;
        }
        return true;
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