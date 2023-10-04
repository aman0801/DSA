class Solution {
public:
    
    int solve(vector<int>& nums, int k, int sum){
        long long total = 0;
        int count = 1;
        
        for(int i=0; i<nums.size(); i++){
            if(total+nums[i]<=sum){
               total = total+nums[i];
            }else{
                count++;
                total = nums[i];
            }
        }
        return count;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low<=high){
            int mid = (low+high)/2;
            int temp = solve(nums, k, mid);
            if(temp>k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};