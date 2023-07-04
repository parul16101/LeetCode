//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
string rev(string str, int n)
{
    if(n==0)
        return "";
    return str[n-1]+rev(str.substr(0,n-1), n-1);
}

string reverseWord(string str){
    
    return rev(str,str.size());
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends