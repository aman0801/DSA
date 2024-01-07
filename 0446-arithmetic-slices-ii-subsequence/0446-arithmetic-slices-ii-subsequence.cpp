class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        unordered_map<long, int> mp[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = static_cast<long>(nums[i]) - nums[j];
                int count_at_j = mp[j][diff]; 

                result += count_at_j;

                mp[i][diff] = mp[i][diff] + count_at_j + 1;
            }
        }

        return result;
    }
};
