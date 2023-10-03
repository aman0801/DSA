class Solution {
public:
     int solve(vector<int>& nums, int num) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            ans = ans + ceil((double)(nums[i]) / (double)(num)); 
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = 0;
        for(auto& i:nums){
            high = max(high, i);
        }
        int ans = INT_MAX;
        int low = 1;
        while(low<=high){
            int mid = (low+high)/2;
            int temp = solve(nums, mid);
            if(temp<=threshold){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};