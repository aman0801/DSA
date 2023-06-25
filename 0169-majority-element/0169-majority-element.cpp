class Solution {
public:
    
    int count(vector<int>& nums, int number, int start, int end){
        int ans = 0;
        for(int i=start; i<=end; i++){
            if(nums[i] == number){
                ans++;
            }
        }
        return ans;
    }
    
    int solve(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start];
        }
        
        int mid = (start+end)/2;
        int left = solve(nums, start, mid);
        int right = solve(nums, mid+1, end);
        
        int countLeft = count(nums, left, start, end);
        int countRight = count(nums, right, start, end);
        
        if(countLeft>countRight){
            return left;
        }
        return right;
        
    }
    
    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};