class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx = 1;
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            int tmp = abs(nums[i]);
            if(nums[tmp]<0){
                ans = tmp;
                break;
            }else{
                nums[tmp] = nums[tmp]*(-1);
            }
        }
        return abs(ans);
    }
};