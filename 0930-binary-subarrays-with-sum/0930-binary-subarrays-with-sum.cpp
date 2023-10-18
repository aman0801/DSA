class Solution {
public:
    
    int solve(vector<int>& nums, int goal){
        
        if (goal < 0)return 0;
        
        int i=0,j=0,count=0,sum=0;
        while(i<nums.size()){
            sum = sum+nums[i];
            cout << sum << endl;
            while(sum>goal){
                sum = sum-nums[j];
                cout << sum << endl;
                j++;
            }
            count = count + i-j+1;
            i++;
        }
        return count;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal)-solve(nums, goal-1);
    }
};