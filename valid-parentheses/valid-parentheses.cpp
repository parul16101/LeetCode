class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                else if(s[i]==')')
                {
                    if(st.top()=='{' || st.top()=='[')
                        return false;
                    else
                        st.pop();
                }
                else if(s[i]==']')
                {
                    if(st.top()=='{' || st.top()=='(')
                        return false;
                    else
                        st.pop();
                }
                else if(s[i]=='}')
                {
                    if(st.top()=='(' || st.top()=='[')
                        return false;
                    else
                        st.pop();
                }
            }
        }
        return st.empty();
    }
};