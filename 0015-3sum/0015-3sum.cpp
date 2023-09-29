class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) mp[nums[i]] = i;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int temp = -1*(nums[i]+nums[j]);
                if(mp.find(temp)!=mp.end() && mp[temp] > j){
                    ans.push_back({nums[i], nums[j], temp});
                }
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
        }
        return ans;
    }
};