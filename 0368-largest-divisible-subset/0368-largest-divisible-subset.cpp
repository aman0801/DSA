class Solution {
public:
        
    void solve(vector<int>& nums, int idx, int prev, vector<int>& temp, vector<int>& ans, vector<int>& dp){
            if(idx>=nums.size()){
                    if(temp.size()>ans.size()){
                            ans = temp;
                    }
                    return;
            }
            
            if((int)temp.size()>dp[idx] && nums[idx]%prev==0){
                    dp[idx] = temp.size();
                    temp.push_back(nums[idx]);
                    solve(nums, idx+1, nums[idx], temp, ans, dp);
                    temp.pop_back();
            }
            solve(nums, idx+1, prev, temp, ans, dp);
    }    
        
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int>ans;
            vector<int>temp;
            vector<int>dp(nums.size(), -1);
            solve(nums, 0, -1, temp, ans, dp);
            return ans;
    }
};