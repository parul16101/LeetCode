class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        map<char,int> mp1;
        map<char,int> mp2;
        if(n!=m)
            return 0;
        
        for(int i=0;i<n;i++)
        {
            mp1[s[i]]+=1;
            mp2[t[i]]+=1;
        }
        return mp1==mp2;
    }
};