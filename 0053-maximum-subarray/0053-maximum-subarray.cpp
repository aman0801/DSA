class Solution {
public:
    
int solve(vector<int>& nums, int l, int r){
        if(l == r){
          return nums[l];  
        }
        
        int mbls = INT_MIN;
        int mbrs = INT_MIN;
        int lbs = 0;
        int rbs = 0;
        int mid = l + (r - l)/2;
        
        int mls = solve(nums, l, mid);
        int mrs = solve(nums, mid+1, r);
        
        for(int i=mid; i>=l; i--){
            lbs = lbs + nums[i];
            mbls = max(mbls, lbs);
        }
        for(int i=mid+1; i<=r; i++){
            rbs = rbs + nums[i];
            mbrs = max(mbrs, rbs);
        }
        
        int ans = mbls + mbrs;
        
        return max(mls, max(mrs, ans));
        
    }
    
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};