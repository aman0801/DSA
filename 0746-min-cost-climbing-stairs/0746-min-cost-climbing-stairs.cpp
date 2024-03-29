class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = 0, curr = 0;
        
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = min(curr + cost[i - 1], prev + cost[i - 2]);
            prev = temp;
        }
        
        return curr;
    }
};
