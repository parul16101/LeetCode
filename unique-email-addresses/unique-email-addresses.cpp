class Solution {
public:
    string filterEmails(string s)
    {
        int n = s.size();
        string ans = "";
        int at = 0;
        int i = 0;
        
        while(i<n)
        {
            if(s[i]=='@')
                {
                
                at = 1;
                }
            if(at==1)
            {
                ans = ans+s[i];
            }
            else if(s[i]=='.' && at==0)
                {
                i+=1;
                continue;
                }
            else if(s[i]=='+' && at==0)
            {
                while(i<n && s[i]!='@')
                    i+=1;
                continue;
            }
            else
                ans = ans+s[i];
            
            i+=1;
        }
        return ans;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        unordered_set<string> st;
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
            ans = filterEmails(emails[i]);
            
            st.insert(ans);
        }
        
        return st.size();
    }
};