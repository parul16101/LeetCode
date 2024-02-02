class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int miniLen = INT_MAX;
        string ans = "";
        int n = strs.size(), f = 0;
        for(int i=0;i<n;i++)
        {
            int len = strs[i].size();
            miniLen = min(miniLen,len);
        }
        
        for(int i=0;i<miniLen;i++)
        {
            char b = strs[0][i];
            f = 0;
            
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=b)
                {
                    f = 1;
                    break;
                }
            }
            if(f==0)
                ans += b;
            else
                break;
        }
        return ans;
    }
};