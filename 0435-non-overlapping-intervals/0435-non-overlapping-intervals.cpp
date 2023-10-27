class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int i = 0, j = 1;
        sort(intervals.begin(), intervals.end());
        while(j<intervals.size()){
            if(intervals[i][1]<=intervals[j][0]){
                i=j;
                j++;
            }else if(intervals[i][1]>intervals[j][1]){
                count++;
                i=j;
                j++;
                
            }else if(intervals[i][1]<=intervals[j][1]){
                count++;
                j++;
            }
        }
        return count;
    }
};