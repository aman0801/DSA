class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> out;  

            unordered_map<int, int> mp;

            for (int j = i; j < nums.size(); j++) {
                if (mp.find(nums[j]) == mp.end() && nums[j] != -1) {
                    out.push_back(nums[j]);
                    mp[nums[j]]++;
                    nums[j] = -1;
                }
            }

             if (!out.empty()) { 
                mp.clear();
                ans.push_back(out);
            }
        }

        return ans;
    }
};
