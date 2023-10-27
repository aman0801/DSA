class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        while(i<intervals.size()){
            if(intervals[i][1] < newInterval[0]){
                i++;
            }else if(intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }else{
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                intervals.erase(intervals.begin()+i);
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};