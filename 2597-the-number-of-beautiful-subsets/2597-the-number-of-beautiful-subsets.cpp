class Solution {
public:
        
    void solve(vector<int>& nums, int k, unordered_map<int, int>& mp, int& ans, int idx){
            if(idx>=nums.size()){
                    ans++;
                    return;
            }
            
            solve(nums, k, mp, ans, idx+1);
            
            if(!mp[nums[idx]-k] && !mp[nums[idx]+k]){
                    mp[nums[idx]]++;
                    solve(nums, k, mp, ans, idx+1);
                    mp[nums[idx]]--;
            }
    }    
        
    int beautifulSubsets(vector<int>& nums, int k) {
            unordered_map<int, int>mp;
            int ans=0;
            solve(nums, k, mp, ans, 0);
            return ans-1;
    }
};