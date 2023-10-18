class Solution {
public:
    
    int solve(vector<int>& nums, int k){
        int i=0,j=0,count=0,ans=0;
        while(i<nums.size()){
            if(nums[i]%2==1){
                count++;
            }
            while(count>k){
                if(nums[j]%2==1){
                    count--;
                }
                j++;
            }
            ans = ans + (i-j+1);
            i++;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k)-solve(nums, k-1);
    }
};