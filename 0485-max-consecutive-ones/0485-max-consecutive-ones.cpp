class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,ans=0;
        while(i<nums.size()){
            if(nums[i] == 1){
                ans = max(ans, i-j+1);
                i++;
            }else{
                j=i+1;
                i++;
            }
        }
        return ans;
    }
};