class Solution {
public:
    
    int solve(vector<int>& nums, int l, int h){
        if(l == h){
            return nums[l];
        }
        
        int la = INT_MIN;
        int ra = INT_MIN;
        int mid = (l + h) >> 1;
        int sum = 0;
        for(int i=mid; i>=l; i--){
            sum = sum + nums[i];
            la = max(la, sum);
        }
        sum=0;
        for(int i=mid+1; i<=h; i++){
            sum = sum + nums[i];
            ra = max(ra, sum);
        }
        
         int maxSumSubarray =  la+ra;
        int leftAnsSum = solve(nums, l, mid);
        int rightAnsSum = solve(nums, mid+1, h);

        return max(maxSumSubarray, max(leftAnsSum, rightAnsSum));
        
    }
    
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
