class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // map<double, int>mp;
        if(points.size()<=2)
            return points.size();
        int res = 0;
        for(int i=0; i<points.size(); i++){
            map<double, int>mp;
            double slope;
            for(int j=i+1; j<points.size(); j++){
               if(points[i][0]==points[j][0]){
                    slope=DBL_MAX;
                }else{
                int sx = points[i][0] - points[j][0];
                int sy = points[i][1] - points[j][1];
                 slope = sy/((double)sx);
                }
                mp[slope]+=1;
            res=max(res, mp[slope]);
            }
        }
        return res+1;
    }
};
