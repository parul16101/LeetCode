class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start;
        vector<int> end;
        
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int ans = 0;
        int count = 0;
        int i = 0, j = 0;
        while(i<n)
        {
            if(start[i]<end[j])
            {
                count+=1;
                ans = max(ans,count);
                i+=1;
            }
            else
            {
                count-=1;
                j+=1;
            }      
        }
        
        return ans;
    }
};