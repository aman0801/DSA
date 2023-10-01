class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++){
            int st = intervals[i][0];
            int end = intervals[i][1];
            
            if(!ans.empty() && ans.back()[1]>=end){
                continue;
            }
            for(int j=i+1; j<intervals.size(); j++){
                if(intervals[j][0]<=end){
                    end = max(end, intervals[j][1]);
                }
            }
            ans.push_back({st, end});
        }
        return ans;
    }
};