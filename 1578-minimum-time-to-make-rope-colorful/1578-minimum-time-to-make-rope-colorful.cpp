class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int prev = 0;
        
        for(int i=0; i<colors.length(); i++){
            if(i>0 && colors[i]!=colors[i-1]){
                prev = 0;
            }
            int curr = neededTime[i];
            ans = ans + min(curr, prev);
            prev = max(prev, curr);
        }
        return ans;
    }
};