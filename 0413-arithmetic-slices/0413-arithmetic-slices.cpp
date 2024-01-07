class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
            int count = 0;
            int total = 0;
            for(int i=2; i<nums.size(); i++){
                    if(nums[i-1]-nums[i-2] == nums[i]-nums[i-1]){
                            count++;
                            total = total+count;
                    }else{
                            count=0;
                    }
            }
            return total;
    }
};