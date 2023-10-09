class Solution {
public:
    static bool cmp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b)
    {
        return a.first<b.first;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,pair<int,int>>> arr;
        int n = points.size();
        int dist = 0;
        
        for(int i=0;i<n;i++)
        {
            int a = points[i][0];
            int b = points[i][1];
            
            dist = a*a+b*b;
            
            arr.push_back({dist,{a,b}});
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<k;i++)
        {
            int x = arr[i].second.first;
            int y = arr[i].second.second;
            
            vector<int> temp;
            temp.push_back(x);
            temp.push_back(y);
            ans.push_back(temp);
        }
        return ans;
    }
};