class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
            if(nums.size()<=2){
                    return -1;
            }
            sort(nums.begin(), nums.end());
            
            long long sum = 0;
            long long ans = -1;
            sum = nums[0]+nums[1];
            for(int i=2; i<nums.size(); i++){
                    if(sum>nums[i]){
                            ans = max(ans, nums[i]+sum);
                    }
                    sum = sum + nums[i];
            }
            return ans;
    }
};

// 1 1 2 3 5 12 50