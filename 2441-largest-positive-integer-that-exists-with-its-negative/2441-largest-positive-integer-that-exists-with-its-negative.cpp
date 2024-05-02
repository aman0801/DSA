class Solution {
public:
    int findMaxK(vector<int>& nums) {
            int ans=-1;
            for(auto& i:nums){
                    for(auto& j:nums){
                            if(i==-j){
                                    ans=max(ans, abs(i));
                            }
                    }
            }
            return ans;
    }
};