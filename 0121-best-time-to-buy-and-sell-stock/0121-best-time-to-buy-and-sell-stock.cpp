class Solution {
public:
    void find_ans(vector<int>& prices, int idx, int &mini, int &maxP){
        if(idx == prices.size()){
            return;
        }
        
        // int mini = INT_MAX;
        // int maxP = INT_MIN;
        
        if(prices[idx] < mini){
            mini = prices[idx];
        }
        int temp = prices[idx] - mini;
        if(temp > maxP){
            maxP = temp;
        }
        
        // idx = idx + 1;
        find_ans(prices, idx+1, mini, maxP);
    }
    int maxProfit(vector<int>& prices) {
        // int idx = 0;
        int mini = INT_MAX;
        int maxP = INT_MIN;
        find_ans(prices, 0, mini, maxP);
        return maxP;
    }
};