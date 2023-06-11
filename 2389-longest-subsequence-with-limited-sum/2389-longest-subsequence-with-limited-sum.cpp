class Solution {
public:
    
    int solve(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int count = -1;
        int m;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m] <= target){
                count = m;
                l = m+1;
            }else{
                r = m - 1;
            }
        }
        return count+1;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            nums[i] = nums[i] + nums[i-1];
        }
        for(auto &i: queries){
            int count = solve(nums, i);
            ans.push_back(count);
        }
        return ans;
    }
};