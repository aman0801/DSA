class Solution {
public:
        
    void solve(vector<int>& nums, int idx, vector<int>& tmp, vector<vector<int>>& subset){
            if(idx == nums.size()){
                    subset.push_back(tmp);
                    return;
            }
            tmp.push_back(nums[idx]);
            solve(nums, idx+1, tmp, subset);
            tmp.pop_back();
            solve(nums, idx+1, tmp, subset);
    }    
        
    int subsetXORSum(vector<int>& nums) {
            vector<int>tmp;
            vector<vector<int>>subset;
            solve(nums, 0, tmp, subset);
            
            int ans=0;
            for(auto& i:subset){
                    int Xor=0;
                    for(auto& j:i){
                            Xor=Xor^j;
                    }
                    ans=ans+Xor;
            }
            return ans;
    }
};