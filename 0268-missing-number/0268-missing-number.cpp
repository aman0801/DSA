class Solution {
public:
    
    int findSum(int n){
    int sum = 0;
    for (int x = 1; x <= n; x++)
        sum = sum + x;
    return sum;
    }
    
    int missingNumber(vector<int>& nums) {
        int sum = findSum(nums.size());
        int sol = 0;
        for(int i=0; i<nums.size(); i++){
            sol = sol+nums[i];
        }
        return abs(sol-sum);
    }
};