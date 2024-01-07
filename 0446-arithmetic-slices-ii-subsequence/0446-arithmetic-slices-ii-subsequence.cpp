class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        unordered_map<long, int> mp[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = static_cast<long>(nums[i]) - nums[j];
                int count = mp[j][diff]; 

                result += count;

                mp[i][diff] = mp[i][diff] + count + 1;
            }
        }

        return result;
    }
};
