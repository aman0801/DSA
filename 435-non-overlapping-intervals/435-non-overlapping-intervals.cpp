class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int l=0;
        int r=1;
         int n = intervals.size();
        while(r<n){
            if(intervals[l][1]<=intervals[r][0]){  
                l=r;
                r+=1;
            }else if(intervals[l][1]<=intervals[r][1]){
                count+=1;
                r+=1;
            }else if(intervals[l][1]>intervals[r][1]){
                count+=1;
                l=r;
                r+=1;
            }
        }
        return count;
    }
};