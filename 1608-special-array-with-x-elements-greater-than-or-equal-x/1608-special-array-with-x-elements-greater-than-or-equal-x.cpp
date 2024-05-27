class Solution {
public:
    bool isPoss(vector<int>& nums, int mid) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= mid) {
                count++;
            }
        }
        return count == mid;
    }
        
    int countGreaterEqual(vector<int>& nums, int mid) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= mid) {
                count++;
            }
        }
        return count;
    }
        
    int specialArray(vector<int>& nums) {
        int i = 0;
        int j = nums.size(); 
        int ans = -1;
        while (i <= j) {
            int mid = (j + i) / 2;
            if (isPoss(nums, mid)) {
                return mid; 
            } else if (countGreaterEqual(nums, mid) > mid) {
                i = mid + 1; 
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }
};