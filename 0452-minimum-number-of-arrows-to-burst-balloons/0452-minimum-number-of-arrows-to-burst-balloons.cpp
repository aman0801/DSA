class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int p = points[0][1];
        int count = 1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0] > p){
                count++;
                p = points[i][1];
              }
            else p=min(p,points[i][1]);
        }
        return count;
    }
};
