class Solution {
public:
    int n;
    void find(vector<int>& nums, int idx, vector<vector<int>>&ans, vector<int>&curr){
        if(curr.size()>=2){
            ans.push_back(curr);
        }
        
        unordered_set<int>st;
        
        for(int i=idx; i<n; i++){
            if((curr.empty() || nums[i] >= curr.back()) && (st.find(nums[i]) == st.end())){
                curr.push_back(nums[i]);
                find(nums, i+1, ans, curr);
                curr.pop_back();
                
                st.insert(nums[i]);
            }
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        n = nums.size();
        
        find(nums, 0, ans, curr);
        return ans;
    }
};