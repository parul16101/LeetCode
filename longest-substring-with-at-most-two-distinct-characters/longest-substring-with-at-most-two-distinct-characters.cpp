class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        
        int i = 0, j = 0;

        int ans = INT_MIN;
        
        while(j<n)
        {
            mp[s[j]]+=1;
            
            while(mp.size()>2)
            {
                mp[s[i]]-=1;
                
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                
                i+=1;
            }
            
            ans = max(ans,j-i+1);
            j+=1;
        }
        
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
};