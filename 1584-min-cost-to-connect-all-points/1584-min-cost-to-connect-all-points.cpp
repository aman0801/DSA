class Solution {
public:
    int dis(vector<int>&d1, vector<int>&d2){
        return (abs(d1[0]-d2[0])+ abs(d1[1]-d2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>vis(n, 0);
        vector<int>minCost(n, INT_MAX);
        int currP = 0;
        minCost[0] = 0;
        int ans = 0;
        
        while(currP>=0){
            vis[currP] = 1;
            int np = -1; //nextpoint
            int mincurr = INT_MAX;
            for(int i=0; i<n; i++){
                if(vis[i] || currP == i){
                    continue;
                }
                minCost[i] = min(dis(points[currP], points[i]), minCost[i]);
                if(minCost[i]<mincurr){
                    mincurr=minCost[i];
                    np = i;
                }
            }
            if(mincurr == INT_MAX){
                ans = ans+0;
            }else{
                ans = ans+mincurr;
            }
            currP = np;
        }
        return ans;
    }
};