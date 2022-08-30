class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>a;
        sort(nums.begin(),nums.end());
        a.push_back(nums);
        
        while(next_permutation(nums.begin(),nums.end())){
            a.push_back(nums);
        }
        return a;
    }
};