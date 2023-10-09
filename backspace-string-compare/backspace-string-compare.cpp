class Solution {
public:
    string checkBackspace(string s)
    {
        stack<char> st;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
                st.push(s[i]);
            else if(!st.empty())
                st.pop();
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
        
        return checkBackspace(s)==checkBackspace(t);
    }
};