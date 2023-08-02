class Solution {
public:
        
     void solve(vector<int>& nums, int idx, vector<int>& out, vector<vector<int>>& ans){
             if(idx>=nums.size()){
                     ans.push_back(out);
                     return;
             }
             
             for(int i=idx; i<nums.size(); i++){
                     swap(out[idx] , out[i]);
                     solve(nums, idx+1, out, ans);
                     swap(out[idx] , out[i]);
             }
     }   
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>out = nums;
        vector<vector<int>>ans;
        solve(nums, 0, out, ans);
            return ans;
    }
};

