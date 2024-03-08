class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
            
        int maxi = 0;
        for (auto x : mp) {
            if (x.second > maxi) {
                maxi = x.second;
            }
        }    
        
        int ans = 0;
        for (auto x : mp) {
            if (x.second == maxi) {
                ans += maxi;
            }
        }    
        return ans;    
    }
};