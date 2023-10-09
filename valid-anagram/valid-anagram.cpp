class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++)
            mp[s[i]]+=1;
        
        for(int i=0;i<m;i++)
        {
            if(mp.find(t[i])==mp.end())
                return 0;
           
            mp[t[i]]-=1;
            
            if(mp[t[i]]==0)
                mp.erase(t[i]);
        }
        
        for(auto i:mp)
        {
            if(i.second!=0)
                return 0;
        }
        
        return 1;
    }
};