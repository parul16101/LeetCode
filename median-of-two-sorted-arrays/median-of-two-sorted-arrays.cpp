class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        vector<int> temp;
        int sz = n+m, even = 0;
        
        if(sz%2==0)
            even = 1;
        
        int index = (sz/2)+1, count= 0;
        
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                temp.push_back(nums1[i]);
                i+=1;
            }
            else
            {
                temp.push_back(nums2[j]);
                j+=1;
            }
            
            count+=1;
            
            if(count==index)
            {
                if(even)
                {
                    return double(temp[count-1]+temp[count-2])/2;
                }
                else
                    return temp[count-1];
            }
        }
        
        while(i<n)
        {
            temp.push_back(nums1[i]);
            i+=1;
            
            count+=1;
            
            if(count==index)
            {
                if(even)
                {
                    return double(temp[count-1]+temp[count-2])/2;
                }
                else
                    return temp[count-1];
            }
        }
        
        while(j<m)
        {
            temp.push_back(nums2[j]);
            j+=1;
            
            count+=1;
            
            if(count==index)
            {
                if(even)
                {
                    return double(temp[count-1]+temp[count-2])/2;
                }
                else
                    return (temp[count-1]);
            }
        }
        
        return 0;
    }
};